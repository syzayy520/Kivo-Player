#pragma once

#include "playback/media_open_public/identity/media_open_public_identity.h"

namespace kivo::playback::stream_selection_public {

struct MediaOpenPublicStreamSelectionAnchor {
    kivo::playback::media_open_public::MediaOpenPublicIdentity open_identity{};
};

} // namespace kivo::playback::stream_selection_public
