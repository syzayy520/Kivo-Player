#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_intake {

enum class P2PublicIntakeKind : std::uint8_t {
    SurfaceOpen,
    SurfaceClose,
    PhaseAdvance,
    Unknown
};

} // namespace kivo::playback::p2_public_intake
