#pragma once

#include <cstdint>

namespace kivo::playback::lifecycle_phase {

enum class PlaybackLifecyclePhaseDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::lifecycle_phase
