#pragma once
#include "playback_session_id.h"
#include "playback_session_generation.h"
#include "playback_session_role.h"
#include "scenario/contracts/identity/scenario_id.h"
namespace kivo::playback::orchestration {
struct PlaybackSessionIdentity {
    PlaybackSessionId session_id{};
    PlaybackSessionGeneration generation{};
    PlaybackSessionRole role{PlaybackSessionRole::Unknown};
    kivo::playback::scenario::ScenarioId scenario_ref{};
};
}
