#pragma once

#include <cstdint>

namespace kivo::playback::seek_public {

enum class SeekPublicScope : std::uint8_t {
    PublicSurface,
    StreamSelection,
    Timeline,
    Unknown
};

} // namespace kivo::playback::seek_public
