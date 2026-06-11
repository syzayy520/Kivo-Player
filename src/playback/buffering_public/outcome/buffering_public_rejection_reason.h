#pragma once

#include <cstdint>

namespace kivo::playback::buffering_public {

enum class BufferingPublicRejectionReason : std::uint8_t {
    SeekAnchorMissing,
    ClassificationInvalid,
    BufferingIdentityMissing,
    Unknown
};

} // namespace kivo::playback::buffering_public
