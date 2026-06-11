#pragma once

#include <cstdint>

namespace kivo::playback::buffering_public {

enum class BufferingPublicDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::buffering_public
