#pragma once

#include <cstdint>

namespace kivo::playback::media_open_public {

enum class MediaOpenPublicKind : std::uint8_t {
    Local,
    External,
    Resume,
    Unknown
};

} // namespace kivo::playback::media_open_public
