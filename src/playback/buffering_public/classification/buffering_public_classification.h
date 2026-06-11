#pragma once

#include "buffering_public_kind.h"
#include "buffering_public_scope.h"

namespace kivo::playback::buffering_public {

struct BufferingPublicClassification {
    BufferingPublicKind kind{BufferingPublicKind::Unknown};
    BufferingPublicScope scope{BufferingPublicScope::Unknown};

    bool operator==(const BufferingPublicClassification& other) const = default;
};

} // namespace kivo::playback::buffering_public
