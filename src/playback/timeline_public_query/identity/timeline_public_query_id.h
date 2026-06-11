#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_query {

struct TimelinePublicQueryId {
    uint64_t value{0};

    bool operator==(const TimelinePublicQueryId& other) const = default;
};

} // namespace kivo::playback::timeline_public_query
