#pragma once

#include "../identity/seek_public_identity.h"
#include "seek_public_status.h"

namespace kivo::playback::seek_public {

struct SeekPublicOutcome {
    SeekPublicIdentity identity{};
    SeekPublicStatus status{SeekPublicStatus::Unknown};

    bool operator==(const SeekPublicOutcome& other) const = default;
};

} // namespace kivo::playback::seek_public
