#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_response {

struct TimelinePublicResponseGeneration {
    uint64_t value{0};

    bool operator==(const TimelinePublicResponseGeneration& other) const = default;
};

} // namespace kivo::playback::timeline_public_response
