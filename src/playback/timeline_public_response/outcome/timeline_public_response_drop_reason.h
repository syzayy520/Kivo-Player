#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_response {

enum class TimelinePublicResponseDropReason : uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::timeline_public_response
