#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_query_delta_response {

struct TimelinePublicQueryDeltaResponseSequenceId {
    std::uint64_t value{0};

    bool operator==(const TimelinePublicQueryDeltaResponseSequenceId& other) const = default;
};

} // namespace kivo::playback::timeline_public_query_delta_response
