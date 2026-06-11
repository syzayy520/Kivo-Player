#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_query {

enum class TimelinePublicQueryDropReason : uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::timeline_public_query
