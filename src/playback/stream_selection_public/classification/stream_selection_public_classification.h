#pragma once

#include "stream_selection_public_kind.h"
#include "stream_selection_public_scope.h"

namespace kivo::playback::stream_selection_public {

struct StreamSelectionPublicClassification {
    StreamSelectionPublicKind kind{StreamSelectionPublicKind::Unknown};
    StreamSelectionPublicScope scope{StreamSelectionPublicScope::Unknown};

    bool operator==(const StreamSelectionPublicClassification& other) const = default;
};

} // namespace kivo::playback::stream_selection_public
