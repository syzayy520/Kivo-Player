#pragma once

#include <cstdint>

namespace kivo::playback::track_transition_public {

struct TrackTransitionPublicSequenceId {
    std::uint64_t value{0};

    bool operator==(const TrackTransitionPublicSequenceId& other) const = default;
};

} // namespace kivo::playback::track_transition_public
