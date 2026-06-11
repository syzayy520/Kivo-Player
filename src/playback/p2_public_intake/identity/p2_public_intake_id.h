#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_intake {

struct P2PublicIntakeId {
    std::uint64_t value{0};

    bool operator==(const P2PublicIntakeId& other) const = default;
};

} // namespace kivo::playback::p2_public_intake
