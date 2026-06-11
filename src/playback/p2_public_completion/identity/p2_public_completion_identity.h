#pragma once

#include "p2_public_completion_id.h"
#include "p2_public_completion_sequence_id.h"
#include "p2_public_completion_generation.h"

namespace kivo::playback::p2_public_completion {

struct P2PublicCompletionIdentity {
    P2PublicCompletionId completion_id{};
    P2PublicCompletionSequenceId sequence_id{};
    P2PublicCompletionGeneration generation{};

    bool operator==(const P2PublicCompletionIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_completion
