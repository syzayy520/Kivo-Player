#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_intake {

enum class P2PublicIntakeDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p2_public_intake
