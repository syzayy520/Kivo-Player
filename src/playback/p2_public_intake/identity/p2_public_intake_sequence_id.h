#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_intake {

struct P2PublicIntakeSequenceId {
    std::uint64_t value{0};

    bool operator==(const P2PublicIntakeSequenceId& other) const = default;
};

} // namespace kivo::playback::p2_public_intake
