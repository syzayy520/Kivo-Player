#pragma once

#include <cstdint>

namespace kivo::playback::stream_selection_public {

enum class StreamSelectionPublicScope : std::uint8_t {
    PublicSurface,
    Media,
    Selection,
    Unknown
};

} // namespace kivo::playback::stream_selection_public
