#pragma once

#include <cstdint>

namespace kivo::playback::end_of_stream_public {

enum class EndOfStreamPublicRejectionReason : std::uint8_t {
    TrackTransitionAnchorMissing,
    ClassificationInvalid,
    EndIdentityMissing,
    Unknown
};

} // namespace kivo::playback::end_of_stream_public
