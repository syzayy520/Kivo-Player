#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_query_delta {

enum class TimelinePublicQueryDeltaKind : std::uint8_t {
    Unspecified,
    QueryToDelta,
    DeltaToQuery,
    FinalAuditLinked
};

} // namespace kivo::playback::timeline_public_query_delta
