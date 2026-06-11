#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_response {

struct TimelinePublicResponseId {
    uint64_t value{0};

    bool operator==(const TimelinePublicResponseId& other) const = default;
};

} // namespace kivo::playback::timeline_public_response
