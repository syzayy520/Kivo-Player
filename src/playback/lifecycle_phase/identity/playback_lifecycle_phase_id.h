#pragma once

#include <cstdint>

namespace kivo::playback::lifecycle_phase {

struct PlaybackLifecyclePhaseId {
    std::uint64_t value{0};

    bool operator==(const PlaybackLifecyclePhaseId& other) const = default;
};

} // namespace kivo::playback::lifecycle_phase
