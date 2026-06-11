#pragma once

#include <cstdint>

namespace kivo::playback::lifecycle_phase {

enum class PlaybackLifecyclePhaseKind : std::uint8_t {
    Created,
    Opened,
    Active,
    Inactive,
    Closed,
    Unknown
};

} // namespace kivo::playback::lifecycle_phase
