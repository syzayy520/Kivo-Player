#include <cassert>
#include <iostream>
#include "playback/timeline_user_status_surface/outcome/timeline_user_status_surface_status.h"
#include "playback/timeline_user_status_surface/outcome/timeline_user_status_rejection_reason.h"
#include "playback/timeline_user_status_surface/outcome/timeline_user_status_drop_reason.h"
#include "playback/timeline_user_status_surface/outcome/timeline_user_status_surface_outcome.h"
namespace kivo::playback::timeline_user_status_surface {
void run_timeline_user_status_outcome_tests() {
    assert(static_cast<int>(TimelineUserStatusSurfaceStatus::Recorded) != static_cast<int>(TimelineUserStatusSurfaceStatus::Unknown));
    assert(static_cast<int>(TimelineUserStatusRejectionReason::AnchorMissing) != static_cast<int>(TimelineUserStatusRejectionReason::Unknown));
    assert(static_cast<int>(TimelineUserStatusDropReason::Superseded) != static_cast<int>(TimelineUserStatusDropReason::Unknown));
    TimelineUserStatusSurfaceOutcome out1;
    assert(out1.identity.surface_id.value == 0);
    assert(out1.status == TimelineUserStatusSurfaceStatus::Unknown);
    TimelineUserStatusSurfaceOutcome out2{{.surface_id{10}, .sequence_id{0}, .generation{0}}, TimelineUserStatusSurfaceStatus::Recorded};
    assert(out2.identity.surface_id.value == 10);
    assert(out2.status == TimelineUserStatusSurfaceStatus::Recorded);
    std::cout << "  timeline_user_status_outcome_tests: ALL PASSED\n";
}
}
