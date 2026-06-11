#pragma once

#include <cstdint>

namespace kivo::playback::media_open_public {

struct MediaOpenPublicGeneration {
    std::uint64_t value{0};

    bool operator==(const MediaOpenPublicGeneration& other) const = default;
};

} // namespace kivo::playback::media_open_public
