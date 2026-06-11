#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_readback {

struct P2PublicReadbackSequenceId {
    std::uint64_t value{0};

    bool operator==(const P2PublicReadbackSequenceId& other) const = default;
};

} // namespace kivo::playback::p2_public_readback
