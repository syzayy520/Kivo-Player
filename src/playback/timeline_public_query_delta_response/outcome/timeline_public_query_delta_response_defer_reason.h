#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_query_delta_response {

enum class TimelinePublicQueryDeltaResponseDeferReason : std::uint8_t {
    None,
    QueryDeltaIdentityMissing,
    ResponseIdentityMissing,
    FinalAuditIdentityMissing
};

} // namespace kivo::playback::timeline_public_query_delta_response
