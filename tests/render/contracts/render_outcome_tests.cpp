#include <cassert>
#include <iostream>
#include "render/contracts/outcome/render_outcome_status.h"
#include "render/contracts/outcome/render_outcome.h"
#include "render/contracts/outcome/render_failure_reason.h"
#include "render/contracts/outcome/render_drop_reason.h"

namespace kivo::playback::render {
void run_render_outcome_tests() {
    // Test RenderOutcomeStatus
    RenderOutcomeStatus status1 = RenderOutcomeStatus::Pending;
    RenderOutcomeStatus status2 = RenderOutcomeStatus::Presented;
    RenderOutcomeStatus status3 = RenderOutcomeStatus::Dropped;
    RenderOutcomeStatus status4 = RenderOutcomeStatus::Failed;
    RenderOutcomeStatus status5 = RenderOutcomeStatus::Cancelled;
    assert(status1 != status2);
    assert(status2 != status3);
    assert(status3 != status4);
    assert(status4 != status5);
    
    // Test RenderOutcome
    RenderOutcome outcome1;
    assert(outcome1.submission_id == 0);
    assert(outcome1.frame_id == 0);
    assert(outcome1.status == RenderOutcomeStatus::Pending);
    assert(outcome1.failure_reason == RenderFailureReason::InternalError);
    assert(outcome1.drop_reason == RenderDropReason::LateFrame);
    assert(outcome1.present_time_us == 0);
    
    RenderOutcome outcome2{
        .submission_id{313233},
        .frame_id{343536},
        .status{RenderOutcomeStatus::Presented},
        .failure_reason{RenderFailureReason::DeviceLost},
        .drop_reason{RenderDropReason::DuplicateFrame},
        .present_time_us{1000000}
    };
    assert(outcome2.submission_id == 313233);
    assert(outcome2.frame_id == 343536);
    assert(outcome2.status == RenderOutcomeStatus::Presented);
    assert(outcome2.failure_reason == RenderFailureReason::DeviceLost);
    assert(outcome2.drop_reason == RenderDropReason::DuplicateFrame);
    assert(outcome2.present_time_us == 1000000);
    
    // Test RenderFailureReason
    RenderFailureReason failure1 = RenderFailureReason::DeviceLost;
    RenderFailureReason failure2 = RenderFailureReason::OutOfMemory;
    RenderFailureReason failure3 = RenderFailureReason::FormatUnsupported;
    RenderFailureReason failure4 = RenderFailureReason::Timeout;
    RenderFailureReason failure5 = RenderFailureReason::InternalError;
    assert(failure1 != failure2);
    assert(failure2 != failure3);
    assert(failure3 != failure4);
    assert(failure4 != failure5);
    
    // Test RenderDropReason
    RenderDropReason drop1 = RenderDropReason::LateFrame;
    RenderDropReason drop2 = RenderDropReason::DuplicateFrame;
    RenderDropReason drop3 = RenderDropReason::Backpressure;
    RenderDropReason drop4 = RenderDropReason::PolicySkip;
    assert(drop1 != drop2);
    assert(drop2 != drop3);
    assert(drop3 != drop4);
    
    std::cout << "  render_outcome_tests: ALL PASSED\n";
}
}
