#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_response {

enum class TimelinePublicResponseKind : uint8_t {
    Snapshot,
    Delta,
    Status,
    Unknown
};

} // namespace kivo::playback::timeline_public_response
