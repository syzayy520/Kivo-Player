#pragma once

#include <cstdint>

namespace kivo::playback::session_public {

enum class PlaybackSessionPublicDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::session_public
