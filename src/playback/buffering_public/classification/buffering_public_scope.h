#pragma once

#include <cstdint>

namespace kivo::playback::buffering_public {

enum class BufferingPublicScope : std::uint8_t {
    PublicSurface,
    Seek,
    Timeline,
    Unknown
};

} // namespace kivo::playback::buffering_public
