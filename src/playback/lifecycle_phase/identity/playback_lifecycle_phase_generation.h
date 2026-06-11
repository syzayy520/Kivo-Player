#pragma once

#include <cstdint>

namespace kivo::playback::lifecycle_phase {

struct PlaybackLifecyclePhaseGeneration {
    std::uint64_t value{0};

    bool operator==(const PlaybackLifecyclePhaseGeneration& other) const = default;
};

} // namespace kivo::playback::lifecycle_phase
