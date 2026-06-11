#pragma once

#include "../identity/playback_session_public_identity.h"
#include "../anchor/playback_session_public_anchor_set.h"
#include "../classification/playback_session_public_classification.h"

namespace kivo::playback::session_public {

struct PlaybackSessionPublic {
    PlaybackSessionPublicIdentity identity{};
    PlaybackSessionPublicAnchorSet anchors{};
    PlaybackSessionPublicClassification classification{};
};

} // namespace kivo::playback::session_public
