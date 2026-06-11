#pragma once

#include <cstdint>

namespace kivo::playback::session_public {

struct PlaybackSessionPublicGeneration {
    std::uint64_t value{0};

    bool operator==(const PlaybackSessionPublicGeneration& other) const = default;
};

} // namespace kivo::playback::session_public
