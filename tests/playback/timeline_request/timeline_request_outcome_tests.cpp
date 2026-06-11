#include <cassert>
#include <iostream>
#include "playback/timeline_request/outcome/timeline_normalization_status.h"
#include "playback/timeline_request/outcome/timeline_normalization_outcome.h"
#include "playback/timeline_request/outcome/timeline_rejection_reason.h"
#include "playback/timeline_request/outcome/timeline_drop_reason.h"
namespace kivo::playback::timeline_request {
void run_timeline_request_outcome_tests() {
    assert(static_cast<int>(TimelineNormalizationStatus::Accepted) != static_cast<int>(TimelineNormalizationStatus::Rejected));
    assert(static_cast<int>(TimelineNormalizationStatus::Dropped) != static_cast<int>(TimelineNormalizationStatus::Unknown));
    assert(static_cast<int>(TimelineRejectionReason::TargetInvalid) != static_cast<int>(TimelineRejectionReason::DeadlineInvalid));
    assert(static_cast<int>(TimelineRejectionReason::SessionInvalid) != static_cast<int>(TimelineRejectionReason::Unknown));
    assert(static_cast<int>(TimelineDropReason::Superseded) != static_cast<int>(TimelineDropReason::PriorityOverridden));
    assert(static_cast<int>(TimelineDropReason::Unknown) != static_cast<int>(TimelineDropReason::Superseded));
    TimelineNormalizationOutcome o1;
    assert(o1.status == TimelineNormalizationStatus::Unknown);
    assert(o1.identity.request_id.value == 0);
    TimelineRequestIdentity ident{.request_id{5}, .sequence_id{6}, .generation{7}};
    TimelineNormalizationOutcome o2{ident, TimelineNormalizationStatus::Accepted};
    assert(o2.identity.request_id.value == 5);
    assert(o2.status == TimelineNormalizationStatus::Accepted);
    std::cout << "  timeline_request_outcome_tests: ALL PASSED\n";
}
}
