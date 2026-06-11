#pragma once

#include <cstdint>

namespace kivo::playback::stream_selection_public {

enum class StreamSelectionPublicKind : std::uint8_t {
    Video,
    Audio,
    Subtitle,
    Unknown
};

} // namespace kivo::playback::stream_selection_public
