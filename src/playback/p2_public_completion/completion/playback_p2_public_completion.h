#pragma once

#include "../identity/p2_public_completion_identity.h"
#include "../anchor/p2_public_completion_anchor_set.h"
#include "../classification/p2_public_completion_classification.h"

namespace kivo::playback::p2_public_completion {

struct PlaybackP2PublicCompletion {
    P2PublicCompletionIdentity identity{};
    P2PublicCompletionAnchorSet anchors{};
    P2PublicCompletionClassification classification{};
};

} // namespace kivo::playback::p2_public_completion
