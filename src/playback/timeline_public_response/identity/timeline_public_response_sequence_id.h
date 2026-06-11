#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_response {

struct TimelinePublicResponseSequenceId {
    uint64_t value{0};

    bool operator==(const TimelinePublicResponseSequenceId& other) const = default;
};

} // namespace kivo::playback::timeline_public_response
