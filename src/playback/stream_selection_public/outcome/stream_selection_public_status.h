#pragma once

#include <cstdint>

namespace kivo::playback::stream_selection_public {

enum class StreamSelectionPublicStatus : std::uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::stream_selection_public
