#include <cassert>
#include <iostream>
#include "execution/contracts/task/execution_task_id.h"
#include "execution/contracts/task/execution_task_kind.h"
#include "execution/contracts/task/execution_task_descriptor.h"
#include "execution/contracts/task/execution_task_deadline.h"

namespace kivo::playback::execution {
void run_execution_task_tests() {
    ExecutionTaskId id1;
    assert(id1.value == 0);
    ExecutionTaskId id2{456};
    assert(id2.value == 456);

    ExecutionTaskKind k1 = ExecutionTaskKind::OneShot;
    ExecutionTaskKind k2 = ExecutionTaskKind::Periodic;
    assert(k1 != k2);

    ExecutionTaskDescriptor desc1;
    assert(desc1.task_id.value == 0);
    assert(desc1.kind == ExecutionTaskKind::Unknown);
    ExecutionTaskDescriptor desc2{.task_id{300}, .kind{ExecutionTaskKind::OneShot}};
    assert(desc2.task_id.value == 300);

    ExecutionTaskDeadline deadline1;
    assert(deadline1.task_id.value == 0);
    assert(deadline1.earliest_start.value == 0);
    assert(deadline1.deadline.deadline_us == 0);
    ExecutionTaskDeadline deadline2{
        .task_id{400},
        .earliest_start{kivo::playback::timeline::MediaTimestamp{{}, 100000}},
        .deadline{kivo::playback::presentation::PresentationDeadline{16666, 500}}
    };
    assert(deadline2.task_id.value == 400);
    assert(deadline2.earliest_start.value == 100000);
    assert(deadline2.deadline.deadline_us == 16666);

    std::cout << "  execution_task_tests: ALL PASSED\n";
}
}
