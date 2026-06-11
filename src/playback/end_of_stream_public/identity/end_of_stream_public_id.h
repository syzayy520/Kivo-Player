#pragma once

#include <cstdint>

namespace kivo::playback::end_of_stream_public {

struct EndOfStreamPublicId {
    std::uint64_t value{0};

    bool operator==(const EndOfStreamPublicId& other) const = default;
};

} // namespace kivo::playback::end_of_stream_public
