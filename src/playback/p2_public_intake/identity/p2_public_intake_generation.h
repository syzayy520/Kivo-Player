#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_intake {

struct P2PublicIntakeGeneration {
    std::uint64_t value{0};

    bool operator==(const P2PublicIntakeGeneration& other) const = default;
};

} // namespace kivo::playback::p2_public_intake
