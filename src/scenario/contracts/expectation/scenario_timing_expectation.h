#pragma once
#include "scenario_expectation_id.h"
#include "core/timeline/timestamp/media_timestamp.h"
#include "core/presentation/timing/presentation_deadline.h"
namespace kivo::playback::scenario {
struct ScenarioTimingExpectation {
    ScenarioExpectationId expectation_id{};
    kivo::playback::timeline::MediaTimestamp expected_position{};
    kivo::playback::presentation::PresentationDeadline deadline{};
};
}
