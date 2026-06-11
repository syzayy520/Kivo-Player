#pragma once

#include "../identity/p2_public_completion_identity.h"
#include "p2_public_completion_status.h"

namespace kivo::playback::p2_public_completion {

struct P2PublicCompletionOutcome {
    P2PublicCompletionIdentity identity{};
    P2PublicCompletionStatus status{P2PublicCompletionStatus::Unknown};

    bool operator==(const P2PublicCompletionOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_completion
