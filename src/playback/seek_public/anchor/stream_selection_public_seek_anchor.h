#pragma once

#include "playback/stream_selection_public/identity/stream_selection_public_identity.h"

namespace kivo::playback::seek_public {

struct StreamSelectionPublicSeekAnchor {
    kivo::playback::stream_selection_public::StreamSelectionPublicIdentity selection_identity{};
};

} // namespace kivo::playback::seek_public
