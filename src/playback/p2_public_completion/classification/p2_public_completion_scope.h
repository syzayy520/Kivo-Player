#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_completion {

enum class P2PublicCompletionScope : std::uint8_t {
    PublicSurface,
    ReadbackBoundary,
    CompletionBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_completion
