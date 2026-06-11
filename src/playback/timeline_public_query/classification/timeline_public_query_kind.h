#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_query {

enum class TimelinePublicQueryKind : uint8_t {
    Snapshot,
    Delta,
    Status,
    Unknown
};

} // namespace kivo::playback::timeline_public_query
