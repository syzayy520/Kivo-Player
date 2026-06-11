#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_completion {

struct P2PublicCompletionGeneration {
    std::uint64_t value{0};

    bool operator==(const P2PublicCompletionGeneration& other) const = default;
};

} // namespace kivo::playback::p2_public_completion
