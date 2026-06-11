#pragma once

#include "playback_lifecycle_phase_session_public_anchor.h"

namespace kivo::playback::session_public {

struct PlaybackSessionPublicAnchorSet {
    PlaybackLifecyclePhaseSessionPublicAnchor phase_anchor{};
};

} // namespace kivo::playback::session_public
