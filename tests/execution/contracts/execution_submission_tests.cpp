#include <cassert>
#include <iostream>
#include "execution/contracts/submission/execution_submission_id.h"
#include "execution/contracts/submission/execution_submission_request.h"
#include "execution/contracts/submission/execution_submission_result.h"
#include "execution/contracts/submission/execution_submission_status.h"

namespace kivo::playback::execution {
void run_execution_submission_tests() {
    ExecutionSubmissionId sid1;
    assert(sid1.value == 0);
    ExecutionSubmissionId sid2{999};
    assert(sid2.value == 999);

    ExecutionSubmissionRequest req1;
    assert(req1.submission_id.value == 0);
    assert(req1.task_id.value == 0);
    assert(req1.lane_id.value == 0);
    assert(req1.task_deadline.task_id.value == 0);
    ExecutionSubmissionRequest req2{
        .submission_id{100},
        .task_id{200},
        .lane_id{300},
        .task_deadline{.task_id{200}}
    };
    assert(req2.submission_id.value == 100);
    assert(req2.task_id.value == 200);
    assert(req2.lane_id.value == 300);

    ExecutionSubmissionResult result1;
    assert(result1.submission_id.value == 0);
    assert(result1.status == ExecutionSubmissionStatus::Unknown);
    assert(result1.tasks_accepted == 0);
    assert(result1.tasks_rejected == 0);
    ExecutionSubmissionResult result2{
        .submission_id{500},
        .status{ExecutionSubmissionStatus::Accepted},
        .tasks_accepted{1},
        .tasks_rejected{0}
    };
    assert(result2.tasks_accepted == 1);

    ExecutionSubmissionStatus s1 = ExecutionSubmissionStatus::Accepted;
    ExecutionSubmissionStatus s2 = ExecutionSubmissionStatus::Rejected;
    ExecutionSubmissionStatus s3 = ExecutionSubmissionStatus::Queued;
    assert(s1 != s2); assert(s2 != s3);

    std::cout << "  execution_submission_tests: ALL PASSED\n";
}
}
