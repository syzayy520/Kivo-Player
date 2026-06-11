#pragma once

#include "../identity/track_transition_public_identity.h"
#include "track_transition_public_status.h"

namespace kivo::playback::track_transition_public {

struct TrackTransitionPublicOutcome {
    TrackTransitionPublicIdentity identity{};
    TrackTransitionPublicStatus status{TrackTransitionPublicStatus::Unknown};

    bool operator==(const TrackTransitionPublicOutcome& other) const = default;
};

} // namespace kivo::playback::track_transition_public
