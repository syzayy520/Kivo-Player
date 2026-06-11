#pragma once

#include <cstdint>

namespace kivo::playback::seek_public {

struct SeekPublicGeneration {
    std::uint64_t value{0};

    bool operator==(const SeekPublicGeneration& other) const = default;
};

} // namespace kivo::playback::seek_public
