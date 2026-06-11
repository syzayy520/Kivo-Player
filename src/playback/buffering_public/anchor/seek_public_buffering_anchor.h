#pragma once

#include "playback/seek_public/identity/seek_public_identity.h"

namespace kivo::playback::buffering_public {

struct SeekPublicBufferingAnchor {
    kivo::playback::seek_public::SeekPublicIdentity seek_identity{};
};

} // namespace kivo::playback::buffering_public
