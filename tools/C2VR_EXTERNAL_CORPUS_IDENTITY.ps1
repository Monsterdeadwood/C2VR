param(
    [string]$GameRoot = 'C:\GOG Games\Crysis 2',
    [string]$OutRoot = $PSScriptRoot
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version 2

# MISSING FACT: exact path+SHA256 identities of overlapping C2 beta/PDB families are not closed.
# WHY NOT COLD: N/A; this tool IS the read-only WAVE-1 COLD closure and performs no runtime experiment.
# PASS: every discovered high-value candidate has root, relative path, byte size, SHA256 and PE machine where applicable.
# FAIL: GameRoot is absent, hashing/reading fails, or output cannot be written without touching the game tree.
# BASELINE MUST HOLD: no file under GameRoot is created, modified, renamed, deleted, launched, loaded or patched.

function Get-PeMachine {
    param([Parameter(Mandatory=$true)][string]$Path)
    try {
        $fs = [System.IO.File]::Open($Path, 'Open', 'Read', 'ReadWrite')
        try {
            $br = New-Object System.IO.BinaryReader($fs)
            if ($fs.Length -lt 64) { return '' }
            $fs.Position = 0
            if ($br.ReadUInt16() -ne 0x5A4D) { return '' }
            $fs.Position = 0x3C
            $pe = $br.ReadInt32()
            if ($pe -lt 0 -or ($pe + 6) -gt $fs.Length) { return '' }
            $fs.Position = $pe
            if ($br.ReadUInt32() -ne 0x00004550) { return '' }
            $machine = $br.ReadUInt16()
            switch ($machine) {
                0x014c { return 'x86/0x014C' }
                0x8664 { return 'x64/0x8664' }
                default { return ('0x{0:X4}' -f $machine) }
            }
        }
        finally { $fs.Dispose() }
    }
    catch { return ('READ_ERROR:' + $_.Exception.Message) }
}

function Get-RootLabel {
    param([string]$Path, [array]$Roots)
    foreach ($r in $Roots) {
        if ($Path.StartsWith($r.Path, [System.StringComparison]::OrdinalIgnoreCase)) {
            return $r.Label
        }
    }
    return 'UNCLASSIFIED'
}

if (-not (Test-Path -LiteralPath $GameRoot -PathType Container)) {
    throw "GameRoot not found: $GameRoot"
}
$GameRoot = (Resolve-Path -LiteralPath $GameRoot).Path

$stamp = Get-Date -Format 'yyyyMMdd_HHmmss'
$resultDir = Join-Path $OutRoot ("C2VR_EXTERNAL_CORPUS_IDENTITY_RESULT_$stamp")
New-Item -ItemType Directory -Force -Path $resultDir | Out-Null

$log = Join-Path $resultDir 'RUN.log'
"C2VR external corpus identity — $(Get-Date -Format o)" | Set-Content -Encoding UTF8 $log
"GameRoot=$GameRoot" | Add-Content -Encoding UTF8 $log
"MODE=READ_ONLY_NO_GAME_LAUNCH_NO_HOOKS_NO_NETWORK" | Add-Content -Encoding UTF8 $log

$wanted = @(
    'Crysis2.exe','Crysis2.pdb',
    'CryGameCrysis2.dll','CryGameCrysis2.pdb',
    'CryAction.dll','CryAction.pdb','CryAction.map',
    'CrySystem.dll','CrySystem.pdb',
    'CryRenderD3D11.dll','CryRenderD3D11.pdb',
    'CryRenderD3D9.dll','CryRenderD3D9.pdb',
    'Cry3DEngine.dll','Cry3DEngine.pdb',
    'CryEntitySystem.dll','CryEntitySystem.pdb',
    'CryNetwork.dll','CryNetwork.pdb'
)
$wantedSet = New-Object 'System.Collections.Generic.HashSet[string]' ([System.StringComparer]::OrdinalIgnoreCase)
foreach ($n in $wanted) { [void]$wantedSet.Add($n) }

$roots = New-Object System.Collections.Generic.List[object]
$roots.Add([pscustomobject]@{ Label='GAME_ROOT'; Path=$GameRoot })

Get-ChildItem -LiteralPath $GameRoot -Directory -ErrorAction SilentlyContinue |
    Where-Object { $_.Name -match '5620|beta|sdk|mod' } |
    ForEach-Object {
        $label = ($_.Name -replace '[^A-Za-z0-9._-]','_').ToUpperInvariant()
        $roots.Add([pscustomobject]@{ Label=$label; Path=$_.FullName })
    }

# Prefer specific roots over GAME_ROOT during classification.
$rootArray = @($roots | Sort-Object { $_.Path.Length } -Descending)

$rows = New-Object System.Collections.Generic.List[object]
$seen = New-Object 'System.Collections.Generic.HashSet[string]' ([System.StringComparer]::OrdinalIgnoreCase)

foreach ($root in $rootArray) {
    "SCAN_ROOT=$($root.Label)|$($root.Path)" | Add-Content -Encoding UTF8 $log
    Get-ChildItem -LiteralPath $root.Path -Recurse -File -ErrorAction SilentlyContinue | ForEach-Object {
        if (-not $wantedSet.Contains($_.Name)) { return }
        if (-not $seen.Add($_.FullName)) { return }

        $hash = (Get-FileHash -Algorithm SHA256 -LiteralPath $_.FullName).Hash.ToUpperInvariant()
        $rel = $_.FullName.Substring($GameRoot.Length).TrimStart('\')
        $ext = $_.Extension.ToLowerInvariant()
        $machine = if ($ext -eq '.dll' -or $ext -eq '.exe') { Get-PeMachine -Path $_.FullName } else { '' }

        $rows.Add([pscustomobject]@{
            RootId       = Get-RootLabel -Path $_.FullName -Roots $rootArray
            RelativePath = $rel
            FileName     = $_.Name
            SizeBytes    = [int64]$_.Length
            SHA256       = $hash
            PEMachine    = $machine
            LastWriteUtc = $_.LastWriteTimeUtc.ToString('o')
        })
        "HASHED=$rel|$($_.Length)|$hash|$machine" | Add-Content -Encoding UTF8 $log
    }
}

$rows = @($rows | Sort-Object RootId, RelativePath)
$tsv = Join-Path $resultDir 'C2VR_EXTERNAL_CORPUS_IDENTITY.tsv'
$json = Join-Path $resultDir 'C2VR_EXTERNAL_CORPUS_IDENTITY.json'
$summary = Join-Path $resultDir 'SUMMARY.txt'

$rows | Export-Csv -Delimiter "`t" -NoTypeInformation -Encoding UTF8 -LiteralPath $tsv
$rows | ConvertTo-Json -Depth 4 | Set-Content -Encoding UTF8 -LiteralPath $json

$groups = $rows | Group-Object FileName | Where-Object { $_.Count -gt 1 }
@(
    'C2VR EXTERNAL CORPUS IDENTITY SUMMARY'
    '===================================='
    "GameRoot: $GameRoot"
    "Candidates hashed: $($rows.Count)"
    "Duplicate filenames with multiple identities: $($groups.Count)"
    ''
    'DUPLICATE-NAME GROUPS:'
    foreach ($g in $groups) {
        "[$($g.Name)] count=$($g.Count)"
        foreach ($x in $g.Group) { "  $($x.RootId) | $($x.RelativePath) | $($x.SizeBytes) | $($x.SHA256) | $($x.PEMachine)" }
    }
) | Set-Content -Encoding UTF8 -LiteralPath $summary

"PASS rows=$($rows.Count) duplicate_name_groups=$($groups.Count)" | Add-Content -Encoding UTF8 $log
Write-Host "PASS: $($rows.Count) high-value identities hashed." -ForegroundColor Green
Write-Host "Result: $resultDir"
Write-Host "Send/retain: C2VR_EXTERNAL_CORPUS_IDENTITY.tsv + SUMMARY.txt"
