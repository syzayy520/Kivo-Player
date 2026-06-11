#pragma once

#include <cstdint>

namespace kivo::playback::buffering_public {

enum class BufferingPublicKind : std::uint8_t {
    Priming,
    Filling,
    Stable,
    Unknown
};

} // namespace kivo::playback::buffering_public
