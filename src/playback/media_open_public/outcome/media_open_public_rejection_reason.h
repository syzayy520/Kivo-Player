#pragma once

#include <cstdint>

namespace kivo::playback::media_open_public {

enum class MediaOpenPublicRejectionReason : std::uint8_t {
    SessionAnchorMissing,
    ClassificationInvalid,
    OpenIdentityMissing,
    Unknown
};

} // namespace kivo::playback::media_open_public
