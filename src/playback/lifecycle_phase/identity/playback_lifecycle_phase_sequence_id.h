#pragma once

#include <cstdint>

namespace kivo::playback::lifecycle_phase {

struct PlaybackLifecyclePhaseSequenceId {
    std::uint64_t value{0};

    bool operator==(const PlaybackLifecyclePhaseSequenceId& other) const = default;
};

} // namespace kivo::playback::lifecycle_phase
