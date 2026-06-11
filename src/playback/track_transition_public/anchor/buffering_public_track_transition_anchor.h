#pragma once

#include "playback/buffering_public/identity/buffering_public_identity.h"

namespace kivo::playback::track_transition_public {

struct BufferingPublicTrackTransitionAnchor {
    kivo::playback::buffering_public::BufferingPublicIdentity buffering_identity{};
};

} // namespace kivo::playback::track_transition_public
