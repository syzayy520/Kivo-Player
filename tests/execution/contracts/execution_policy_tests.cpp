#include <cassert>
#include <iostream>
#include "execution/contracts/policy/execution_realtime_policy.h"
#include "execution/contracts/policy/execution_blocking_policy.h"
#include "execution/contracts/policy/execution_cancellation_policy.h"
#include "execution/contracts/policy/execution_ordering_policy.h"

namespace kivo::playback::execution {
void run_execution_policy_tests() {
    ExecutionRealtimePolicy rp1 = ExecutionRealtimePolicy::RealtimeForbidden;
    ExecutionRealtimePolicy rp2 = ExecutionRealtimePolicy::RealtimeCompatible;
    ExecutionRealtimePolicy rp3 = ExecutionRealtimePolicy::RealtimeRequired;
    assert(rp1 != rp2); assert(rp2 != rp3);

    ExecutionBlockingPolicy bp1 = ExecutionBlockingPolicy::NonBlockingRequired;
    ExecutionBlockingPolicy bp2 = ExecutionBlockingPolicy::BoundedBlockingAllowed;
    ExecutionBlockingPolicy bp3 = ExecutionBlockingPolicy::BlockingAllowed;
    assert(bp1 != bp2); assert(bp2 != bp3);

    ExecutionCancellationPolicy cp1 = ExecutionCancellationPolicy::NotCancellable;
    ExecutionCancellationPolicy cp2 = ExecutionCancellationPolicy::Cooperative;
    ExecutionCancellationPolicy cp3 = ExecutionCancellationPolicy::DeadlineOnly;
    assert(cp1 != cp2); assert(cp2 != cp3);

    ExecutionOrderingPolicy op1 = ExecutionOrderingPolicy::Ordered;
    ExecutionOrderingPolicy op2 = ExecutionOrderingPolicy::Unordered;
    ExecutionOrderingPolicy op3 = ExecutionOrderingPolicy::LatestOnly;
    assert(op1 != op2); assert(op2 != op3);

    std::cout << "  execution_policy_tests: ALL PASSED\n";
}
}
