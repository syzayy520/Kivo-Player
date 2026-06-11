#pragma once

#include <cstdint>

namespace kivo::playback::end_of_stream_public {

enum class EndOfStreamPublicScope : std::uint8_t {
    PublicSurface,
    TrackTransition,
    Timeline,
    Unknown
};

} // namespace kivo::playback::end_of_stream_public
