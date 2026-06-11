#pragma once

#include <cstdint>

namespace kivo::playback::seek_public {

enum class SeekPublicKind : std::uint8_t {
    Absolute,
    Relative,
    Resume,
    Unknown
};

} // namespace kivo::playback::seek_public
