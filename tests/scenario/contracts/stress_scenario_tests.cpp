#include <cassert>
#include <iostream>
#include "scenario/contracts/stress/stress_scenario_id.h"
#include "scenario/contracts/stress/stress_pressure_kind.h"
#include "scenario/contracts/stress/stress_pressure_level.h"
#include "scenario/contracts/stress/stress_scenario_descriptor.h"

namespace kivo::playback::scenario {
void run_stress_scenario_tests() {
    StressScenarioId id1;
    assert(id1.value == 0);
    StressScenarioId id2{456};
    assert(id2.value == 456);

    StressPressureKind k1 = StressPressureKind::Startup;
    StressPressureKind k2 = StressPressureKind::Seek;
    StressPressureKind k3 = StressPressureKind::TrackSwitch;
    StressPressureKind k4 = StressPressureKind::FormatSwitch;
    StressPressureKind k5 = StressPressureKind::DeviceChange;
    StressPressureKind k6 = StressPressureKind::MemoryPressure;
    assert(k1 != k2); assert(k2 != k3); assert(k3 != k4);
    assert(k4 != k5); assert(k5 != k6);

    StressPressureLevel l1 = StressPressureLevel::Low;
    StressPressureLevel l2 = StressPressureLevel::Medium;
    StressPressureLevel l3 = StressPressureLevel::High;
    StressPressureLevel l4 = StressPressureLevel::Extreme;
    assert(l1 != l2); assert(l2 != l3); assert(l3 != l4);

    StressScenarioDescriptor desc1;
    assert(desc1.stress_id.value == 0);
    assert(desc1.pressure_kind == StressPressureKind::Unknown);
    assert(desc1.pressure_level == StressPressureLevel::Unknown);
    StressScenarioDescriptor desc2{.stress_id{500}, .pressure_kind{StressPressureKind::Seek}, .pressure_level{StressPressureLevel::High}};
    assert(desc2.stress_id.value == 500);
    assert(desc2.pressure_kind == StressPressureKind::Seek);

    std::cout << "  stress_scenario_tests: ALL PASSED\n";
}
}
