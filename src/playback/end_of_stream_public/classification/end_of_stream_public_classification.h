#pragma once

#include "end_of_stream_public_kind.h"
#include "end_of_stream_public_scope.h"

namespace kivo::playback::end_of_stream_public {

struct EndOfStreamPublicClassification {
    EndOfStreamPublicKind kind{EndOfStreamPublicKind::Unknown};
    EndOfStreamPublicScope scope{EndOfStreamPublicScope::Unknown};

    bool operator==(const EndOfStreamPublicClassification& other) const = default;
};

} // namespace kivo::playback::end_of_stream_public
