#pragma once

#include "seek_public_kind.h"
#include "seek_public_scope.h"

namespace kivo::playback::seek_public {

struct SeekPublicClassification {
    SeekPublicKind kind{SeekPublicKind::Unknown};
    SeekPublicScope scope{SeekPublicScope::Unknown};

    bool operator==(const SeekPublicClassification& other) const = default;
};

} // namespace kivo::playback::seek_public
