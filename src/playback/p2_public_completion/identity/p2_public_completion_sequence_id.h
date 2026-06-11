#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_completion {

struct P2PublicCompletionSequenceId {
    std::uint64_t value{0};

    bool operator==(const P2PublicCompletionSequenceId& other) const = default;
};

} // namespace kivo::playback::p2_public_completion
