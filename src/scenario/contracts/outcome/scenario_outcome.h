#pragma once
#include "../identity/scenario_id.h"
#include "scenario_outcome_status.h"
namespace kivo::playback::scenario {
struct ScenarioOutcome {
    ScenarioId scenario_id{};
    ScenarioOutcomeStatus status{ScenarioOutcomeStatus::Unknown};
};
}
