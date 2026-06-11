#pragma once

#include "../identity/media_open_public_identity.h"
#include "../anchor/media_open_public_anchor_set.h"
#include "../classification/media_open_public_classification.h"

namespace kivo::playback::media_open_public {

struct MediaOpenPublicCandidate {
    MediaOpenPublicIdentity identity{};
    MediaOpenPublicAnchorSet anchors{};
    MediaOpenPublicClassification classification{};
};

} // namespace kivo::playback::media_open_public
