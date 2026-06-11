#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_response {

enum class TimelinePublicResponseRejectionReason : uint8_t {
    QueryAnchorMissing,
    ClassificationInvalid,
    ResponseIdentityMissing,
    Unknown
};

} // namespace kivo::playback::timeline_public_response
