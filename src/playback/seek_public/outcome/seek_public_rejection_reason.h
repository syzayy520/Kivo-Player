#pragma once

#include <cstdint>

namespace kivo::playback::seek_public {

enum class SeekPublicRejectionReason : std::uint8_t {
    StreamSelectionAnchorMissing,
    ClassificationInvalid,
    SeekIdentityMissing,
    Unknown
};

} // namespace kivo::playback::seek_public
