#pragma once

#include <cstdint>

namespace kivo::playback::stream_selection_public {

enum class StreamSelectionPublicRejectionReason : std::uint8_t {
    MediaOpenAnchorMissing,
    ClassificationInvalid,
    SelectionIdentityMissing,
    Unknown
};

} // namespace kivo::playback::stream_selection_public
