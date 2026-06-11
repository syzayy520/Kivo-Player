#pragma once

#include "../identity/stream_selection_public_identity.h"
#include "stream_selection_public_status.h"

namespace kivo::playback::stream_selection_public {

struct StreamSelectionPublicOutcome {
    StreamSelectionPublicIdentity identity{};
    StreamSelectionPublicStatus status{StreamSelectionPublicStatus::Unknown};

    bool operator==(const StreamSelectionPublicOutcome& other) const = default;
};

} // namespace kivo::playback::stream_selection_public
