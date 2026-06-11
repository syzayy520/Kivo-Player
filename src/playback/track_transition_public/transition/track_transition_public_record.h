#pragma once

#include "track_transition_public_envelope.h"
#include "playback_track_transition_public.h"

namespace kivo::playback::track_transition_public {

struct TrackTransitionPublicRecord {
    TrackTransitionPublicEnvelope envelope{};
    PlaybackTrackTransitionPublic transition{};
};

} // namespace kivo::playback::track_transition_public
