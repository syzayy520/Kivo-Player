#pragma once

#include "../identity/end_of_stream_public_identity.h"
#include "../anchor/end_of_stream_public_anchor_set.h"
#include "../classification/end_of_stream_public_classification.h"

namespace kivo::playback::end_of_stream_public {

struct PlaybackEndOfStreamPublic {
    EndOfStreamPublicIdentity identity{};
    EndOfStreamPublicAnchorSet anchors{};
    EndOfStreamPublicClassification classification{};
};

} // namespace kivo::playback::end_of_stream_public
