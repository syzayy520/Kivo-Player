#pragma once
#include "../identity/control_identity.h"
#include "../source/control_source_identity.h"
#include "../command/playback_control_command.h"
#include "../target/playback_control_target.h"
#include "control_normalization_policy.h"
#include "control_normalization_decision.h"
#include "normalized_playback_intent.h"
namespace kivo::playback::control {
struct ControlNormalizationRecord {
    ControlIdentity identity{};
    ControlSourceIdentity source{};
    PlaybackControlCommand command{};
    PlaybackControlTarget target{};
    ControlNormalizationPolicy policy{ControlNormalizationPolicy::Unknown};
    NormalizedPlaybackIntent normalized_intent{};
    ControlNormalizationDecision decision{ControlNormalizationDecision::Unknown};
};
}
