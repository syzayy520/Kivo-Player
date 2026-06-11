#pragma once

#include <cstdint>

namespace kivo::playback::media_open_public {

enum class MediaOpenPublicDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::media_open_public
