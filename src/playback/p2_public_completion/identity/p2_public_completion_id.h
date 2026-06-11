#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_completion {

struct P2PublicCompletionId {
    std::uint64_t value{0};

    bool operator==(const P2PublicCompletionId& other) const = default;
};

} // namespace kivo::playback::p2_public_completion
