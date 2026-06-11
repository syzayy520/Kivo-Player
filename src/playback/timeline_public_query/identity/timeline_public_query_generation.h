#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_query {

struct TimelinePublicQueryGeneration {
    uint64_t value{0};

    bool operator==(const TimelinePublicQueryGeneration& other) const = default;
};

} // namespace kivo::playback::timeline_public_query
