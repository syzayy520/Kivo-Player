#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_response {

enum class TimelinePublicResponseScope : uint8_t {
    Current,
    Since,
    Window,
    PublicSafe,
    Unknown
};

} // namespace kivo::playback::timeline_public_response
