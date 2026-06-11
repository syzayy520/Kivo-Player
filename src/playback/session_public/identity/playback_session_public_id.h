#pragma once

#include <cstdint>

namespace kivo::playback::session_public {

struct PlaybackSessionPublicId {
    std::uint64_t value{0};

    bool operator==(const PlaybackSessionPublicId& other) const = default;
};

} // namespace kivo::playback::session_public
