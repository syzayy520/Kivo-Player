#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_completion {

enum class P2PublicCompletionStatus : std::uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::p2_public_completion
