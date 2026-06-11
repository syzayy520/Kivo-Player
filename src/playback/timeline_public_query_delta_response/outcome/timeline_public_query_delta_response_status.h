#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_query_delta_response {

enum class TimelinePublicQueryDeltaResponseStatus : std::uint8_t {
    Pending,
    Accepted,
    Deferred,
    Rejected
};

} // namespace kivo::playback::timeline_public_query_delta_response
