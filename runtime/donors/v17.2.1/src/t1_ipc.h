#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdint.h>

#define C2VR_T1_MAGIC 0x37315243u /* CR17 */
#define C2VR_T1_VERSION 0x00170200u
#define C2VR_T1_MAP_NAME L"Local\\C2VR_RC33_TRUE_LR_V172"

#pragma pack(push,4)
struct T1FrameContract {
    uint64_t contract_id;
    uint64_t predicted_display_time;
    float head_q[4];
    float center_pos_m[3];
    float eye_pos_head_m[2][3];
    float eye_q[2][4];              /* exact recenter-space XrView orientation */
    float eye_pos_m[2][3];          /* exact recenter-space XrView position */
    float fov[2][4];
    LONG  right_valid;
    float right_q_head[4];          /* right aim orientation relative to HMD */
    float right_pos_head_m[3];      /* right aim position relative to HMD center */
    float right_trigger;
    float right_grip;
};

struct T1Shared {
    uint32_t magic,version;
    volatile LONG host_alive,game_alive,session_running,views_valid,faulted,legacy_violation;
    volatile LONG contract_seq;
    T1FrameContract contract;

    volatile LONG pair_seq;
    volatile LONG pair_contract_seq;
    T1FrameContract pair_contract;  /* immutable exact contract that produced the published pixels */
    volatile LONG eye_ready_mask;

    uint32_t game_w,game_h,game_format,xr_recommended_w,xr_recommended_h;
    uint64_t shared_handle[2];

    volatile LONG renderworld_calls,center_inject_ok,center_restore_ok,cull_union_ok;
    volatile LONG scene_packets,custom_pairs_queued,pairs_completed;
    volatile LONG eye_camera_ok[2],eye_camera_fail[2],rt_push_eye[2],rt_scene_eye[2];
    volatile LONG temporal_snap[2],temporal_restore[2],shadow_skip[2];
    volatile LONG direct_pair_copies,direct_pair_copy_fail,host_pairs_consumed,host_submits,xr_capture_count;
    volatile LONG frame_desync,pose_desync,duplicate_eye_warn,near_events[3],activation_beep_ready;
    volatile LONG semantic_world_eye[2],semantic_near_eye[2],semantic_other_eye[2],semantic_unknown_eye;
    volatile LONG hand_near_eye[2],hand_baseline_resets,right_action_valid,trigger_events;
    volatile LONG two_pass_active,center_scene_suppressed,mirror_left_ok,mirror_left_fail;
    volatile LONG xr_frame_requests,xr_frame_exact_hits,xr_frame_misses,host_frame_gate_skips,pair_contract_mismatch;
    uint64_t last_requested_contract,last_completed_contract;
    uint64_t semantic_world_hash[2],semantic_near_hash[2];
    float last_axis_dot,last_cull_fov,last_ipd_mm,last_left_fov[4],last_right_fov[4];
    float last_hand_delta_m[3],last_hand_angle_deg,last_pair_mae,pair_wait_ms_last,pair_wait_ms_max;
    uint64_t last_pair_hash[2];
    char fault_text[256];
};
#pragma pack(pop)
#ifdef __cplusplus
static_assert(sizeof(T1FrameContract)==196, "T1FrameContract ABI mismatch");
static_assert(sizeof(T1Shared)==1084, "T1Shared ABI mismatch");
#endif
