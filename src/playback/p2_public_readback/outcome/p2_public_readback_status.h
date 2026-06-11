#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_readback {

enum class P2PublicReadbackStatus : std::uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::p2_public_readback
