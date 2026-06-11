#pragma once

#include "../identity/p2_public_readback_identity.h"
#include "../anchor/p2_public_readback_anchor_set.h"
#include "../classification/p2_public_readback_classification.h"

namespace kivo::playback::p2_public_readback {

struct P2PublicReadbackEnvelope {
    P2PublicReadbackIdentity identity{};
    P2PublicReadbackAnchorSet anchors{};
    P2PublicReadbackClassification classification{};
};

} // namespace kivo::playback::p2_public_readback
