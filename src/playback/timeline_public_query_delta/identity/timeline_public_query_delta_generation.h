#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_query_delta {

struct TimelinePublicQueryDeltaGeneration {
    std::uint64_t value{0};

    bool operator==(const TimelinePublicQueryDeltaGeneration& other) const = default;
};

} // namespace kivo::playback::timeline_public_query_delta
