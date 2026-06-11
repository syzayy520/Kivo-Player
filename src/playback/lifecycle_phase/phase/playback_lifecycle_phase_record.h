#pragma once

#include "playback_lifecycle_phase_envelope.h"
#include "playback_lifecycle_phase.h"

namespace kivo::playback::lifecycle_phase {

struct PlaybackLifecyclePhaseRecord {
    PlaybackLifecyclePhaseEnvelope envelope{};
    PlaybackLifecyclePhase phase{};
};

} // namespace kivo::playback::lifecycle_phase
