#pragma once

#include <cstdint>

namespace kivo::playback::lifecycle_phase {

enum class PlaybackLifecyclePhaseStatus : std::uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::lifecycle_phase
