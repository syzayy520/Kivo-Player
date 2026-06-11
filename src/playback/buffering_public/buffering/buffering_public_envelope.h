#pragma once

#include "../identity/buffering_public_identity.h"
#include "../anchor/buffering_public_anchor_set.h"
#include "../classification/buffering_public_classification.h"

namespace kivo::playback::buffering_public {

struct BufferingPublicEnvelope {
    BufferingPublicIdentity identity{};
    BufferingPublicAnchorSet anchors{};
    BufferingPublicClassification classification{};
};

} // namespace kivo::playback::buffering_public
