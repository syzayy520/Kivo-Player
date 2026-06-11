#pragma once

#include <cstdint>

namespace kivo::playback::session_public {

enum class PlaybackSessionPublicStatus : std::uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::session_public
