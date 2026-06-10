#include <cassert>
#include <iostream>
#include "execution/contracts/context/execution_context_id.h"
#include "execution/contracts/context/execution_context_role.h"
#include "execution/contracts/context/execution_context_identity.h"
#include "execution/contracts/context/execution_context_snapshot.h"

namespace kivo::playback::execution {
void run_execution_context_tests() {
    ExecutionContextId id1;
    assert(id1.value == 0);
    ExecutionContextId id2{42};
    assert(id2.value == 42);

    ExecutionContextRole r1 = ExecutionContextRole::Control;
    ExecutionContextRole r2 = ExecutionContextRole::RealtimeCandidate;
    ExecutionContextRole r3 = ExecutionContextRole::Background;
    ExecutionContextRole r4 = ExecutionContextRole::Diagnostic;
    assert(r1 != r2); assert(r2 != r3); assert(r3 != r4);

    ExecutionContextIdentity ident1;
    assert(ident1.id.value == 0);
    assert(ident1.role == ExecutionContextRole::Unknown);
    ExecutionContextIdentity ident2{.id{100}, .role{ExecutionContextRole::Control}};
    assert(ident2.id.value == 100);

    ExecutionContextSnapshot snap1;
    assert(snap1.context_id.value == 0);
    assert(snap1.healthy == true);
    ExecutionContextSnapshot snap2{.context_id{200}, .healthy{false}};
    assert(snap2.context_id.value == 200);
    assert(snap2.healthy == false);

    std::cout << "  execution_context_tests: ALL PASSED\n";
}
void run_execution_lane_tests();
void run_execution_task_tests();
void run_execution_submission_tests();
void run_execution_policy_tests();
void run_execution_outcome_tests();
}

int main() {
    using namespace kivo::playback::execution;
    run_execution_context_tests();
    run_execution_lane_tests();
    run_execution_task_tests();
    run_execution_submission_tests();
    run_execution_policy_tests();
    run_execution_outcome_tests();
    std::cout << "  ALL execution contracts tests PASSED\n";
    return 0;
}
