#pragma once

#include "../identity/playback_lifecycle_phase_identity.h"
#include "playback_lifecycle_phase_status.h"

namespace kivo::playback::lifecycle_phase {

struct PlaybackLifecyclePhaseOutcome {
    PlaybackLifecyclePhaseIdentity identity{};
    PlaybackLifecyclePhaseStatus status{PlaybackLifecyclePhaseStatus::Unknown};

    bool operator==(const PlaybackLifecyclePhaseOutcome& other) const = default;
};

} // namespace kivo::playback::lifecycle_phase
