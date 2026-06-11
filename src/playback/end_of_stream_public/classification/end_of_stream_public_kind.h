#pragma once

#include <cstdint>

namespace kivo::playback::end_of_stream_public {

enum class EndOfStreamPublicKind : std::uint8_t {
    Natural,
    Forced,
    Interrupted,
    Unknown
};

} // namespace kivo::playback::end_of_stream_public
