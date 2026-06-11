#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_query_delta_response {

struct TimelinePublicQueryDeltaResponseKey {
    std::uint64_t value{0};

    bool operator==(const TimelinePublicQueryDeltaResponseKey& other) const = default;
};

} // namespace kivo::playback::timeline_public_query_delta_response
