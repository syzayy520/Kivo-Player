#pragma once

#include "../identity/stream_selection_public_identity.h"
#include "../anchor/stream_selection_public_anchor_set.h"
#include "../classification/stream_selection_public_classification.h"

namespace kivo::playback::stream_selection_public {

struct StreamSelectionPublicCandidate {
    StreamSelectionPublicIdentity identity{};
    StreamSelectionPublicAnchorSet anchors{};
    StreamSelectionPublicClassification classification{};
};

} // namespace kivo::playback::stream_selection_public
