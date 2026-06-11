#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_query_delta_response {

enum class TimelinePublicQueryDeltaResponseRejectionReason : std::uint8_t {
    None,
    QueryDeltaResponseMismatch,
    UpstreamIdentityMismatch,
    FinalAuditMismatch
};

} // namespace kivo::playback::timeline_public_query_delta_response
