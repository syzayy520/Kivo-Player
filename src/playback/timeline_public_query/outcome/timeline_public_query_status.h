#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_query {

enum class TimelinePublicQueryStatus : uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::timeline_public_query
