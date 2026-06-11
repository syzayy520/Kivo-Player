#pragma once

#include <cstdint>

namespace kivo::playback::track_transition_public {

struct TrackTransitionPublicGeneration {
    std::uint64_t value{0};

    bool operator==(const TrackTransitionPublicGeneration& other) const = default;
};

} // namespace kivo::playback::track_transition_public
