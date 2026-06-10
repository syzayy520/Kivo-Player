#pragma once
#include "scenario_expectation_id.h"
namespace kivo::playback::scenario {
struct ScenarioRecoveryExpectation {
    ScenarioExpectationId expectation_id{};
    bool recovery_expected{false};
};
}
