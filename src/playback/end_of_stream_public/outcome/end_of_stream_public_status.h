#pragma once

#include <cstdint>

namespace kivo::playback::end_of_stream_public {

enum class EndOfStreamPublicStatus : std::uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::end_of_stream_public
