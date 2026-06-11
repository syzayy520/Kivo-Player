#pragma once

#include <cstdint>

namespace kivo::playback::session_public {

struct PlaybackSessionPublicSequenceId {
    std::uint64_t value{0};

    bool operator==(const PlaybackSessionPublicSequenceId& other) const = default;
};

} // namespace kivo::playback::session_public
