#include <cassert>
#include <iostream>
#include <vector>
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
    
    // Test RenderSubmissionRequest (approved: vector<RenderFrameId> + RenderTargetId)
    RenderSubmissionRequest request1;
    assert(request1.submission_id.value == 0);
    assert(request1.frame_ids.empty());
    assert(request1.target_id.value == 0);
    
    RenderSubmissionRequest request2{
        .submission_id{252627},
        .frame_ids{RenderFrameId{1}, RenderFrameId{2}, RenderFrameId{3}},
        .target_id{102030}
    };
    assert(request2.submission_id.value == 252627);
    assert(request2.frame_ids.size() == 3);
    assert(request2.frame_ids[0].value == 1);
    assert(request2.frame_ids[1].value == 2);
    assert(request2.frame_ids[2].value == 3);
    assert(request2.target_id.value == 102030);
    
    // Test RenderSubmissionResult (approved: RenderSubmissionStatus + frames_accepted + frames_dropped)
    RenderSubmissionResult result1;
    assert(result1.submission_id.value == 0);
    assert(result1.status == RenderSubmissionStatus::Unknown);
    assert(result1.frames_accepted == 0);
    assert(result1.frames_dropped == 0);
    
    RenderSubmissionResult result2{
        .submission_id{282930},
        .status{RenderSubmissionStatus::Accepted},
        .frames_accepted{3},
        .frames_dropped{0}
    };
    assert(result2.submission_id.value == 282930);
    assert(result2.status == RenderSubmissionStatus::Accepted);
    assert(result2.frames_accepted == 3);
    assert(result2.frames_dropped == 0);
    
    // Test RenderSubmissionStatus (approved: Accepted,Partial,Rejected,Queued,Unknown)
    RenderSubmissionStatus status1 = RenderSubmissionStatus::Accepted;
    RenderSubmissionStatus status2 = RenderSubmissionStatus::Partial;
    RenderSubmissionStatus status3 = RenderSubmissionStatus::Rejected;
    RenderSubmissionStatus status4 = RenderSubmissionStatus::Queued;
    RenderSubmissionStatus status5 = RenderSubmissionStatus::Unknown;
    assert(status1 != status2);
    assert(status2 != status3);
    assert(status3 != status4);
    assert(status4 != status5);
    
    std::cout << "  render_submission_tests: ALL PASSED\n";
}
}

// main() is in render_identity_tests.cpp
