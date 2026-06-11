#pragma once

#include <cstdint>

namespace kivo::playback::buffering_public {

enum class BufferingPublicStatus : std::uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::buffering_public
