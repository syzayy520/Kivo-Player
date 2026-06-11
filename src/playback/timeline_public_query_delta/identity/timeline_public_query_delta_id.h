#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_query_delta {

struct TimelinePublicQueryDeltaId {
    std::uint64_t value{0};

    bool operator==(const TimelinePublicQueryDeltaId& other) const = default;
};

} // namespace kivo::playback::timeline_public_query_delta
