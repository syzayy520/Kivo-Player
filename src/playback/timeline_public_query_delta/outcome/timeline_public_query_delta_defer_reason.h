#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_query_delta {

enum class TimelinePublicQueryDeltaDeferReason : std::uint8_t {
    None,
    QueryIdentityMissing,
    DeltaIdentityMissing,
    FinalAuditIdentityMissing
};

} // namespace kivo::playback::timeline_public_query_delta
