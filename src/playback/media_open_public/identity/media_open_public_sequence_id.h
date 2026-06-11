#pragma once

#include <cstdint>

namespace kivo::playback::media_open_public {

struct MediaOpenPublicSequenceId {
    std::uint64_t value{0};

    bool operator==(const MediaOpenPublicSequenceId& other) const = default;
};

} // namespace kivo::playback::media_open_public
