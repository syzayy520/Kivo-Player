#pragma once
#include "scenario_expectation_id.h"
#include "core/presentation/decision/presentation_decision.h"
namespace kivo::playback::scenario {
struct ScenarioPresentationExpectation {
    ScenarioExpectationId expectation_id{};
    kivo::playback::presentation::PresentationDecision expected_decision{
        kivo::playback::presentation::PresentationDecision::Unknown
    };
};
}
