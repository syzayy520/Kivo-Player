#include <cassert>
#include <iostream>
#include "scenario/contracts/identity/scenario_id.h"
#include "scenario/contracts/identity/scenario_kind.h"
#include "scenario/contracts/identity/scenario_priority.h"
#include "scenario/contracts/identity/scenario_identity.h"

namespace kivo::playback::scenario {
void run_scenario_identity_tests() {
    ScenarioId id1;
    assert(id1.value == 0);
    ScenarioId id2{42};
    assert(id2.value == 42);

    ScenarioKind k1 = ScenarioKind::MediaCase;
    ScenarioKind k2 = ScenarioKind::StressCase;
    ScenarioKind k3 = ScenarioKind::BoundaryCase;
    ScenarioKind k4 = ScenarioKind::RecoveryCase;
    assert(k1 != k2); assert(k2 != k3); assert(k3 != k4);

    ScenarioPriority p1 = ScenarioPriority::Low;
    ScenarioPriority p2 = ScenarioPriority::Medium;
    ScenarioPriority p3 = ScenarioPriority::High;
    ScenarioPriority p4 = ScenarioPriority::Critical;
    assert(p1 != p2); assert(p2 != p3); assert(p3 != p4);

    ScenarioIdentity ident1;
    assert(ident1.scenario_id.value == 0);
    assert(ident1.kind == ScenarioKind::Unknown);
    assert(ident1.priority == ScenarioPriority::Unknown);
    ScenarioIdentity ident2{.scenario_id{100}, .kind{ScenarioKind::MediaCase}, .priority{ScenarioPriority::High}};
    assert(ident2.scenario_id.value == 100);
    assert(ident2.kind == ScenarioKind::MediaCase);
    assert(ident2.priority == ScenarioPriority::High);

    std::cout << "  scenario_identity_tests: ALL PASSED\n";
}
void run_media_case_tests();
void run_stress_scenario_tests();
void run_scenario_expectation_tests();
void run_scenario_risk_tests();
void run_scenario_outcome_tests();
}

int main() {
    using namespace kivo::playback::scenario;
    run_scenario_identity_tests();
    run_media_case_tests();
    run_stress_scenario_tests();
    run_scenario_expectation_tests();
    run_scenario_risk_tests();
    run_scenario_outcome_tests();
    std::cout << "  ALL scenario contracts tests PASSED\n";
    return 0;
}
