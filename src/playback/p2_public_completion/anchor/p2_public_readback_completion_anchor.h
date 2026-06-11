#pragma once

#include "playback/p2_public_readback/identity/p2_public_readback_identity.h"

namespace kivo::playback::p2_public_completion {

struct P2PublicReadbackCompletionAnchor {
    kivo::playback::p2_public_readback::P2PublicReadbackIdentity readback_identity{};
};

} // namespace kivo::playback::p2_public_completion
