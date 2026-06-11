#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_query_delta {

enum class TimelinePublicQueryDeltaRejectionReason : std::uint8_t {
    None,
    QueryDeltaMismatch,
    UpstreamIdentityMismatch,
    FinalAuditMismatch
};

} // namespace kivo::playback::timeline_public_query_delta
