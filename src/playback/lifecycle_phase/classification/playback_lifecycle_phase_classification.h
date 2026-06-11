#pragma once

#include "playback_lifecycle_phase_kind.h"
#include "playback_lifecycle_phase_scope.h"

namespace kivo::playback::lifecycle_phase {

struct PlaybackLifecyclePhaseClassification {
    PlaybackLifecyclePhaseKind kind{PlaybackLifecyclePhaseKind::Unknown};
    PlaybackLifecyclePhaseScope scope{PlaybackLifecyclePhaseScope::Unknown};

    bool operator==(const PlaybackLifecyclePhaseClassification& other) const = default;
};

} // namespace kivo::playback::lifecycle_phase
