#include <cassert>
#include <iostream>
#include "execution/contracts/lane/execution_lane_id.h"
#include "execution/contracts/lane/execution_lane_role.h"
#include "execution/contracts/lane/execution_lane_binding.h"
#include "execution/contracts/lane/execution_lane_capacity.h"

namespace kivo::playback::execution {
void run_execution_lane_tests() {
    ExecutionLaneId id1;
    assert(id1.value == 0);
    ExecutionLaneId id2{789};
    assert(id2.value == 789);

    ExecutionLaneRole r1 = ExecutionLaneRole::Exclusive;
    ExecutionLaneRole r2 = ExecutionLaneRole::Shared;
    ExecutionLaneRole r3 = ExecutionLaneRole::Diagnostic;
    assert(r1 != r2); assert(r2 != r3);

    ExecutionLaneBinding bind1;
    assert(bind1.lane_id.value == 0);
    assert(bind1.context_id.value == 0);
    ExecutionLaneBinding bind2{.lane_id{10}, .context_id{20}};
    assert(bind2.lane_id.value == 10);
    assert(bind2.context_id.value == 20);

    ExecutionLaneCapacity cap1;
    assert(cap1.max_concurrent == 0);
    ExecutionLaneCapacity cap2{16};
    assert(cap2.max_concurrent == 16);

    std::cout << "  execution_lane_tests: ALL PASSED\n";
}
}
