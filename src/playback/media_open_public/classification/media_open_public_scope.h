#pragma once

#include <cstdint>

namespace kivo::playback::media_open_public {

enum class MediaOpenPublicScope : std::uint8_t {
    PublicSurface,
    Session,
    Media,
    Unknown
};

} // namespace kivo::playback::media_open_public
