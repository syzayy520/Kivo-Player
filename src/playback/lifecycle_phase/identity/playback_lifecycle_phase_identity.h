#pragma once

#include "playback_lifecycle_phase_id.h"
#include "playback_lifecycle_phase_sequence_id.h"
#include "playback_lifecycle_phase_generation.h"

namespace kivo::playback::lifecycle_phase {

struct PlaybackLifecyclePhaseIdentity {
    PlaybackLifecyclePhaseId phase_id{};
    PlaybackLifecyclePhaseSequenceId sequence_id{};
    PlaybackLifecyclePhaseGeneration generation{};

    bool operator==(const PlaybackLifecyclePhaseIdentity& other) const = default;
};

} // namespace kivo::playback::lifecycle_phase
