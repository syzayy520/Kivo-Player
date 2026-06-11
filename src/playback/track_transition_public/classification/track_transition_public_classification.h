#pragma once

#include "track_transition_public_kind.h"
#include "track_transition_public_scope.h"

namespace kivo::playback::track_transition_public {

struct TrackTransitionPublicClassification {
    TrackTransitionPublicKind kind{TrackTransitionPublicKind::Unknown};
    TrackTransitionPublicScope scope{TrackTransitionPublicScope::Unknown};

    bool operator==(const TrackTransitionPublicClassification& other) const = default;
};

} // namespace kivo::playback::track_transition_public
