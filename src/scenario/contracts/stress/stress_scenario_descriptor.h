#pragma once
#include "stress_scenario_id.h"
#include "stress_pressure_kind.h"
#include "stress_pressure_level.h"
namespace kivo::playback::scenario {
struct StressScenarioDescriptor {
    StressScenarioId stress_id{};
    StressPressureKind pressure_kind{StressPressureKind::Unknown};
    StressPressureLevel pressure_level{StressPressureLevel::Unknown};
};
}
