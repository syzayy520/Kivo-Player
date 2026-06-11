#pragma once

#include <cstdint>

namespace kivo::playback::session_public {

enum class PlaybackSessionPublicScope : std::uint8_t {
    PublicSurface,
    Lifecycle,
    Session,
    Unknown
};

} // namespace kivo::playback::session_public
