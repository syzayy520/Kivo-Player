#pragma once
#include "scenario_id.h"
#include "scenario_kind.h"
#include "scenario_priority.h"
namespace kivo::playback::scenario {
struct ScenarioIdentity {
    ScenarioId scenario_id{};
    ScenarioKind kind{ScenarioKind::Unknown};
    ScenarioPriority priority{ScenarioPriority::Unknown};
};
}
