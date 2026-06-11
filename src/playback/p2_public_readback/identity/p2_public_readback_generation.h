#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_readback {

struct P2PublicReadbackGeneration {
    std::uint64_t value{0};

    bool operator==(const P2PublicReadbackGeneration& other) const = default;
};

} // namespace kivo::playback::p2_public_readback
