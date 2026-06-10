#include <cassert>
#include <iostream>
#include "render/contracts/outcome/render_outcome_status.h"
#include "render/contracts/outcome/render_outcome.h"
#include "render/contracts/outcome/render_failure_reason.h"
#include "render/contracts/outcome/render_drop_reason.h"

namespace kivo::playback::render {
void run_render_outcome_tests() {
    // Test RenderOutcomeStatus (approved: Rendered,Dropped,Failed,Skipped,Unknown)
    RenderOutcomeStatus status1 = RenderOutcomeStatus::Rendered;
    RenderOutcomeStatus status2 = RenderOutcomeStatus::Dropped;
    RenderOutcomeStatus status3 = RenderOutcomeStatus::Failed;
    RenderOutcomeStatus status4 = RenderOutcomeStatus::Skipped;
    RenderOutcomeStatus status5 = RenderOutcomeStatus::Unknown;
    assert(status1 != status2);
    assert(status2 != status3);
    assert(status3 != status4);
    assert(status4 != status5);
    
    // Test RenderOutcome (approved: typed RenderSubmissionId + RenderFrameId + status only)
    RenderOutcome outcome1;
    assert(outcome1.submission_id.value == 0);
    assert(outcome1.frame_id.value == 0);
    assert(outcome1.status == RenderOutcomeStatus::Unknown);
    
    RenderOutcome outcome2{
        .submission_id{RenderSubmissionId{313233}},
        .frame_id{RenderFrameId{343536}},
        .status{RenderOutcomeStatus::Rendered}
    };
    assert(outcome2.submission_id.value == 313233);
    assert(outcome2.frame_id.value == 343536);
    assert(outcome2.status == RenderOutcomeStatus::Rendered);
    
    // Test RenderFailureReason (approved: TargetUnavailable,SurfaceInvalid,SubmissionTimedOut,ResourceExhaustion,Unknown)
    RenderFailureReason failure1 = RenderFailureReason::TargetUnavailable;
    RenderFailureReason failure2 = RenderFailureReason::SurfaceInvalid;
    RenderFailureReason failure3 = RenderFailureReason::SubmissionTimedOut;
    RenderFailureReason failure4 = RenderFailureReason::ResourceExhaustion;
    RenderFailureReason failure5 = RenderFailureReason::Unknown;
    assert(failure1 != failure2);
    assert(failure2 != failure3);
    assert(failure3 != failure4);
    assert(failure4 != failure5);
    
    // Test RenderDropReason (approved: LatePresentation,QueuePressure,PolicyOverride,GenerationStale,Unknown)
    RenderDropReason drop1 = RenderDropReason::LatePresentation;
    RenderDropReason drop2 = RenderDropReason::QueuePressure;
    RenderDropReason drop3 = RenderDropReason::PolicyOverride;
    RenderDropReason drop4 = RenderDropReason::GenerationStale;
    RenderDropReason drop5 = RenderDropReason::Unknown;
    assert(drop1 != drop2);
    assert(drop2 != drop3);
    assert(drop3 != drop4);
    assert(drop4 != drop5);
    
    std::cout << "  render_outcome_tests: ALL PASSED\n";
}
}

// main() is in render_identity_tests.cpp
