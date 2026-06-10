#include <cassert>
#include <iostream>
#include "execution/contracts/outcome/execution_outcome_status.h"
#include "execution/contracts/outcome/execution_outcome.h"
#include "execution/contracts/outcome/execution_failure_reason.h"
#include "execution/contracts/outcome/execution_drop_reason.h"

namespace kivo::playback::execution {
void run_execution_outcome_tests() {
    ExecutionOutcomeStatus s1 = ExecutionOutcomeStatus::Completed;
    ExecutionOutcomeStatus s2 = ExecutionOutcomeStatus::Dropped;
    ExecutionOutcomeStatus s3 = ExecutionOutcomeStatus::Failed;
    ExecutionOutcomeStatus s4 = ExecutionOutcomeStatus::Cancelled;
    assert(s1 != s2); assert(s2 != s3); assert(s3 != s4);

    ExecutionOutcome outcome1;
    assert(outcome1.submission_id.value == 0);
    assert(outcome1.status == ExecutionOutcomeStatus::Unknown);
    ExecutionOutcome outcome2{
        .submission_id{ExecutionSubmissionId{777}},
        .status{ExecutionOutcomeStatus::Completed}
    };
    assert(outcome2.submission_id.value == 777);
    assert(outcome2.status == ExecutionOutcomeStatus::Completed);

    ExecutionFailureReason f1 = ExecutionFailureReason::TaskInvalid;
    ExecutionFailureReason f2 = ExecutionFailureReason::LaneUnavailable;
    ExecutionFailureReason f3 = ExecutionFailureReason::DeadlineExceeded;
    ExecutionFailureReason f4 = ExecutionFailureReason::ResourceExhaustion;
    assert(f1 != f2); assert(f2 != f3); assert(f3 != f4);

    ExecutionDropReason d1 = ExecutionDropReason::Overdue;
    ExecutionDropReason d2 = ExecutionDropReason::QueuePressure;
    ExecutionDropReason d3 = ExecutionDropReason::Preempted;
    assert(d1 != d2); assert(d2 != d3);

    std::cout << "  execution_outcome_tests: ALL PASSED\n";
}
}
