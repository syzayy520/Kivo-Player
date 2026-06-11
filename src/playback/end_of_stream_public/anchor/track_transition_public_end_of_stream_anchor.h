#pragma once

#include "playback/track_transition_public/identity/track_transition_public_identity.h"

namespace kivo::playback::end_of_stream_public {

struct TrackTransitionPublicEndOfStreamAnchor {
    kivo::playback::track_transition_public::TrackTransitionPublicIdentity transition_identity{};
};

} // namespace kivo::playback::end_of_stream_public
