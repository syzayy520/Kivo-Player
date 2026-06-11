#pragma once

#include <cstdint>

namespace kivo::playback::end_of_stream_public {

enum class EndOfStreamPublicDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::end_of_stream_public
