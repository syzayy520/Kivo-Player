#pragma once

#include "p2_public_completion_kind.h"
#include "p2_public_completion_scope.h"

namespace kivo::playback::p2_public_completion {

struct P2PublicCompletionClassification {
    P2PublicCompletionKind kind{P2PublicCompletionKind::Unknown};
    P2PublicCompletionScope scope{P2PublicCompletionScope::Unknown};

    bool operator==(const P2PublicCompletionClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_completion
