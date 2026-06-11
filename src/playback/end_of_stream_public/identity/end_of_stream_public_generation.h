#pragma once

#include <cstdint>

namespace kivo::playback::end_of_stream_public {

struct EndOfStreamPublicGeneration {
    std::uint64_t value{0};

    bool operator==(const EndOfStreamPublicGeneration& other) const = default;
};

} // namespace kivo::playback::end_of_stream_public
