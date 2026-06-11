#include <cassert>
#include <iostream>
#include "playback/timeline_error_surface/outcome/timeline_error_surface_status.h"
#include "playback/timeline_error_surface/outcome/timeline_error_rejection_reason.h"
#include "playback/timeline_error_surface/outcome/timeline_error_drop_reason.h"
#include "playback/timeline_error_surface/outcome/timeline_error_surface_outcome.h"
namespace kivo::playback::timeline_error_surface {
void run_timeline_error_outcome_tests() {
    assert(static_cast<int>(TimelineErrorSurfaceStatus::Recorded) != static_cast<int>(TimelineErrorSurfaceStatus::Unknown));
    assert(static_cast<int>(TimelineErrorRejectionReason::AnchorMissing) != static_cast<int>(TimelineErrorRejectionReason::Unknown));
    assert(static_cast<int>(TimelineErrorDropReason::Superseded) != static_cast<int>(TimelineErrorDropReason::Unknown));
    TimelineErrorSurfaceOutcome out1;
    assert(out1.identity.surface_id.value == 0);
    assert(out1.status == TimelineErrorSurfaceStatus::Unknown);
    TimelineErrorSurfaceOutcome out2{{.surface_id{10}, .sequence_id{0}, .generation{0}}, TimelineErrorSurfaceStatus::Recorded};
    assert(out2.identity.surface_id.value == 10);
    assert(out2.status == TimelineErrorSurfaceStatus::Recorded);
    std::cout << "  timeline_error_outcome_tests: ALL PASSED\n";
}
}
