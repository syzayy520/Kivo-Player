#pragma once

#include <cstdint>

namespace kivo::playback::stream_selection_public {

enum class StreamSelectionPublicDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::stream_selection_public
