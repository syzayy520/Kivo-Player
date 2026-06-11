#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_completion {

enum class P2PublicCompletionDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p2_public_completion
