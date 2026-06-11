#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_query {

struct TimelinePublicQuerySequenceId {
    uint64_t value{0};

    bool operator==(const TimelinePublicQuerySequenceId& other) const = default;
};

} // namespace kivo::playback::timeline_public_query
