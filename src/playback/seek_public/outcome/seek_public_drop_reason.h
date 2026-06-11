#pragma once

#include <cstdint>

namespace kivo::playback::seek_public {

enum class SeekPublicDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::seek_public
