#pragma once

#include "p2_public_readback_completion_anchor.h"

namespace kivo::playback::p2_public_completion {

struct P2PublicCompletionAnchorSet {
    P2PublicReadbackCompletionAnchor readback_anchor{};
};

} // namespace kivo::playback::p2_public_completion
