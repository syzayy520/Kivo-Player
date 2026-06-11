#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_response {

enum class TimelinePublicResponseStatus : uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::timeline_public_response
