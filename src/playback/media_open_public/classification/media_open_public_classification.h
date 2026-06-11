#pragma once

#include "media_open_public_kind.h"
#include "media_open_public_scope.h"

namespace kivo::playback::media_open_public {

struct MediaOpenPublicClassification {
    MediaOpenPublicKind kind{MediaOpenPublicKind::Unknown};
    MediaOpenPublicScope scope{MediaOpenPublicScope::Unknown};

    bool operator==(const MediaOpenPublicClassification& other) const = default;
};

} // namespace kivo::playback::media_open_public
