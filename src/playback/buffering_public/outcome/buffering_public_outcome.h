#pragma once

#include "../identity/buffering_public_identity.h"
#include "buffering_public_status.h"

namespace kivo::playback::buffering_public {

struct BufferingPublicOutcome {
    BufferingPublicIdentity identity{};
    BufferingPublicStatus status{BufferingPublicStatus::Unknown};

    bool operator==(const BufferingPublicOutcome& other) const = default;
};

} // namespace kivo::playback::buffering_public
