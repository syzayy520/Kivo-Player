#pragma once

#include <cstdint>

namespace kivo::playback::session_public {

enum class PlaybackSessionPublicKind : std::uint8_t {
    Created,
    Bound,
    Active,
    Released,
    Unknown
};

} // namespace kivo::playback::session_public
