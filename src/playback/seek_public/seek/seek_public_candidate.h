#pragma once

#include "../identity/seek_public_identity.h"
#include "../anchor/seek_public_anchor_set.h"
#include "../classification/seek_public_classification.h"

namespace kivo::playback::seek_public {

struct SeekPublicCandidate {
    SeekPublicIdentity identity{};
    SeekPublicAnchorSet anchors{};
    SeekPublicClassification classification{};
};

} // namespace kivo::playback::seek_public
