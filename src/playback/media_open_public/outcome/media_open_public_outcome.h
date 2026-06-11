#pragma once

#include "../identity/media_open_public_identity.h"
#include "media_open_public_status.h"

namespace kivo::playback::media_open_public {

struct MediaOpenPublicOutcome {
    MediaOpenPublicIdentity identity{};
    MediaOpenPublicStatus status{MediaOpenPublicStatus::Unknown};

    bool operator==(const MediaOpenPublicOutcome& other) const = default;
};

} // namespace kivo::playback::media_open_public
