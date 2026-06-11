#pragma once

#include <cstdint>

namespace kivo::playback::lifecycle_phase {

enum class PlaybackLifecyclePhaseScope : std::uint8_t {
    PublicSurface,
    Session,
    Timeline,
    Unknown
};

} // namespace kivo::playback::lifecycle_phase
