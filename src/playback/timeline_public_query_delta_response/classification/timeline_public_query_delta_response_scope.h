#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_query_delta_response {

enum class TimelinePublicQueryDeltaResponseScope : std::uint8_t {
    Unspecified,
    PublicTimeline,
    PublicResponse,
    FinalAudit
};

} // namespace kivo::playback::timeline_public_query_delta_response
