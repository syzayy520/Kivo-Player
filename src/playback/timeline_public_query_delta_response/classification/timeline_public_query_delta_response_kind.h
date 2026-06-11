#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_query_delta_response {

enum class TimelinePublicQueryDeltaResponseKind : std::uint8_t {
    Unspecified,
    QueryDeltaToResponse,
    ResponseToQueryDelta,
    FinalAuditLinked
};

} // namespace kivo::playback::timeline_public_query_delta_response
