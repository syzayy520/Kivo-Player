#pragma once

#include <cstdint>

namespace kivo::playback::seek_public {

enum class SeekPublicStatus : std::uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::seek_public
