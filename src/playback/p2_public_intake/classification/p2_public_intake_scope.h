#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_intake {

enum class P2PublicIntakeScope : std::uint8_t {
    PublicSurface,
    ClosureBoundary,
    IntakeBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_intake
