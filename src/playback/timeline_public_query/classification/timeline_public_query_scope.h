#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_query {

enum class TimelinePublicQueryScope : uint8_t {
    Current,
    Since,
    Window,
    PublicSafe,
    Unknown
};

} // namespace kivo::playback::timeline_public_query
