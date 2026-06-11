#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_completion {

enum class P2PublicCompletionKind : std::uint8_t {
    Acknowledged,
    PartialComplete,
    FullComplete,
    Unknown
};

} // namespace kivo::playback::p2_public_completion
