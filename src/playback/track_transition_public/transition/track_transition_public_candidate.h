#pragma once

#include "../identity/track_transition_public_identity.h"
#include "../anchor/track_transition_public_anchor_set.h"
#include "../classification/track_transition_public_classification.h"

namespace kivo::playback::track_transition_public {

struct TrackTransitionPublicCandidate {
    TrackTransitionPublicIdentity identity{};
    TrackTransitionPublicAnchorSet anchors{};
    TrackTransitionPublicClassification classification{};
};

} // namespace kivo::playback::track_transition_public
