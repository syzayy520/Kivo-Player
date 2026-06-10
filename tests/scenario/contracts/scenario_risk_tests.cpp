#include <cassert>
#include <iostream>
#include "scenario/contracts/risk/scenario_risk_id.h"
#include "scenario/contracts/risk/scenario_risk_kind.h"
#include "scenario/contracts/risk/scenario_risk_level.h"
#include "scenario/contracts/risk/scenario_risk_marker.h"

namespace kivo::playback::scenario {
void run_scenario_risk_tests() {
    ScenarioRiskId id1;
    assert(id1.value == 0);
    ScenarioRiskId id2{333};
    assert(id2.value == 333);

    ScenarioRiskKind k1 = ScenarioRiskKind::Timing;
    ScenarioRiskKind k2 = ScenarioRiskKind::Memory;
    ScenarioRiskKind k3 = ScenarioRiskKind::Device;
    ScenarioRiskKind k4 = ScenarioRiskKind::Format;
    ScenarioRiskKind k5 = ScenarioRiskKind::Recovery;
    assert(k1 != k2); assert(k2 != k3); assert(k3 != k4); assert(k4 != k5);

    ScenarioRiskLevel l1 = ScenarioRiskLevel::Low;
    ScenarioRiskLevel l2 = ScenarioRiskLevel::Medium;
    ScenarioRiskLevel l3 = ScenarioRiskLevel::High;
    ScenarioRiskLevel l4 = ScenarioRiskLevel::Critical;
    assert(l1 != l2); assert(l2 != l3); assert(l3 != l4);

    ScenarioRiskMarker marker1;
    assert(marker1.risk_id.value == 0);
    assert(marker1.kind == ScenarioRiskKind::Unknown);
    assert(marker1.level == ScenarioRiskLevel::Unknown);
    ScenarioRiskMarker marker2{.risk_id{700}, .kind{ScenarioRiskKind::Timing}, .level{ScenarioRiskLevel::Critical}};
    assert(marker2.kind == ScenarioRiskKind::Timing);
    assert(marker2.level == ScenarioRiskLevel::Critical);

    std::cout << "  scenario_risk_tests: ALL PASSED\n";
}
}
