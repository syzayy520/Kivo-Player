#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_query_delta {

enum class TimelinePublicQueryDeltaScope : std::uint8_t {
    Unspecified,
    PublicTimeline,
    PublicSurface,
    FinalAudit
};

} // namespace kivo::playback::timeline_public_query_delta
