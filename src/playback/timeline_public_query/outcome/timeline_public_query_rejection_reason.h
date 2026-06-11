#pragma once

#include <cstdint>

namespace kivo::playback::timeline_public_query {

enum class TimelinePublicQueryRejectionReason : uint8_t {
    DeltaAnchorMissing,
    ClassificationInvalid,
    QueryIdentityMissing,
    Unknown
};

} // namespace kivo::playback::timeline_public_query
