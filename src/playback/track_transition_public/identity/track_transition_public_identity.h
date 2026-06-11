#pragma once

#include "track_transition_public_id.h"
#include "track_transition_public_sequence_id.h"
#include "track_transition_public_generation.h"

namespace kivo::playback::track_transition_public {

struct TrackTransitionPublicIdentity {
    TrackTransitionPublicId transition_id{};
    TrackTransitionPublicSequenceId sequence_id{};
    TrackTransitionPublicGeneration generation{};

    bool operator==(const TrackTransitionPublicIdentity& other) const = default;
};

} // namespace kivo::playback::track_transition_public
