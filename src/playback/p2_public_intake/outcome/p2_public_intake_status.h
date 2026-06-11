#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_intake {

enum class P2PublicIntakeStatus : std::uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::p2_public_intake
