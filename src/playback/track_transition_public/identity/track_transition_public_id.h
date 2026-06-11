#pragma once

#include <cstdint>

namespace kivo::playback::track_transition_public {

struct TrackTransitionPublicId {
    std::uint64_t value{0};

    bool operator==(const TrackTransitionPublicId& other) const = default;
};

} // namespace kivo::playback::track_transition_public
