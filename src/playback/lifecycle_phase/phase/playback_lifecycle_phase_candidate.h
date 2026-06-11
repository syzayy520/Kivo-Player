#pragma once

#include "../identity/playback_lifecycle_phase_identity.h"
#include "../anchor/playback_lifecycle_phase_anchor_set.h"
#include "../classification/playback_lifecycle_phase_classification.h"

namespace kivo::playback::lifecycle_phase {

struct PlaybackLifecyclePhaseCandidate {
    PlaybackLifecyclePhaseIdentity identity{};
    PlaybackLifecyclePhaseAnchorSet anchors{};
    PlaybackLifecyclePhaseClassification classification{};
};

} // namespace kivo::playback::lifecycle_phase
