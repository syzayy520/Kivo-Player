#pragma once

#include <cstdint>

namespace kivo::playback::media_open_public {

struct MediaOpenPublicId {
    std::uint64_t value{0};

    bool operator==(const MediaOpenPublicId& other) const = default;
};

} // namespace kivo::playback::media_open_public
