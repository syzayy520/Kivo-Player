#pragma once

#include "playback/lifecycle_phase/identity/playback_lifecycle_phase_identity.h"

namespace kivo::playback::session_public {

struct PlaybackLifecyclePhaseSessionPublicAnchor {
    kivo::playback::lifecycle_phase::PlaybackLifecyclePhaseIdentity phase_identity{};
};

} // namespace kivo::playback::session_public
