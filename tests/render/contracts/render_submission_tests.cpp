#include <cassert>
#include <iostream>
#include "render/contracts/submission/render_submission_id.h"
#include "render/contracts/submission/render_submission_request.h"
#include "render/contracts/submission/render_submission_result.h"
#include "render/contracts/submission/render_submission_status.h"

namespace kivo::playback::render {
void run_render_submission_tests() {
    // Test RenderSubmissionId
    RenderSubmissionId submission_id1;
    assert(submission_id1.value == 0);
    RenderSubmissionId submission_id2{222324};
    assert(submission_id2.value == 222324);
    
    // Test RenderSubmissionRequest
    RenderSubmissionRequest request1;
    assert(request1.submission_id.value == 0);
    assert(request1.target_time.value == 0);
    
    RenderSubmissionRequest request2{
        .submission_id{252627},
        .target_time{.value{50000}}
    };
    assert(request2.submission_id.value == 252627);
    assert(request2.target_time.value == 50000);
    
    // Test RenderSubmissionResult
    RenderSubmissionResult result1;
    assert(result1.submission_id.value == 0);
    assert(result1.status == RenderOutcomeStatus::Pending);
    
    RenderSubmissionResult result2{
        .submission_id{282930},
        .status{RenderOutcomeStatus::Presented}
    };
    assert(result2.submission_id.value == 282930);
    assert(result2.status == RenderOutcomeStatus::Presented);
    
    // Test RenderSubmissionStatus
    RenderSubmissionStatus status1 = RenderSubmissionStatus::Queued;
    RenderSubmissionStatus status2 = RenderSubmissionStatus::InProgress;
    RenderSubmissionStatus status3 = RenderSubmissionStatus::Completed;
    RenderSubmissionStatus status4 = RenderSubmissionStatus::Dropped;
    RenderSubmissionStatus status5 = RenderSubmissionStatus::Failed;
    assert(status1 != status2);
    assert(status2 != status3);
    assert(status3 != status4);
    assert(status4 != status5);
    
    std::cout << "  render_submission_tests: ALL PASSED\n";
}
}

// main() is in render_identity_tests.cpp
