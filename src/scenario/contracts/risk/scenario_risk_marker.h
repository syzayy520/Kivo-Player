#pragma once
#include "scenario_risk_id.h"
#include "scenario_risk_kind.h"
#include "scenario_risk_level.h"
namespace kivo::playback::scenario {
struct ScenarioRiskMarker {
    ScenarioRiskId risk_id{};
    ScenarioRiskKind kind{ScenarioRiskKind::Unknown};
    ScenarioRiskLevel level{ScenarioRiskLevel::Unknown};
};
}
