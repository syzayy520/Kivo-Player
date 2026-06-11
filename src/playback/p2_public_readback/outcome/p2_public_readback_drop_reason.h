#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_readback {

enum class P2PublicReadbackDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p2_public_readback
