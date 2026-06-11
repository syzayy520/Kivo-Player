#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_readback {

enum class P2PublicReadbackKind : std::uint8_t {
    SurfaceSnapshot,
    AdmissionSnapshot,
    ChainSnapshot,
    Unknown
};

} // namespace kivo::playback::p2_public_readback
