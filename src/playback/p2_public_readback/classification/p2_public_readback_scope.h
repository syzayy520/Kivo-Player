#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_readback {

enum class P2PublicReadbackScope : std::uint8_t {
    PublicSurface,
    AdmissionBoundary,
    ReadbackBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_readback
