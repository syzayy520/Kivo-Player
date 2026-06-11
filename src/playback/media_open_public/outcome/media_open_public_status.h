#pragma once

#include <cstdint>

namespace kivo::playback::media_open_public {

enum class MediaOpenPublicStatus : std::uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::media_open_public
