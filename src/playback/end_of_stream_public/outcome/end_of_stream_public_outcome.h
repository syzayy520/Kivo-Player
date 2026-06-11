#pragma once

#include "../identity/end_of_stream_public_identity.h"
#include "end_of_stream_public_status.h"

namespace kivo::playback::end_of_stream_public {

struct EndOfStreamPublicOutcome {
    EndOfStreamPublicIdentity identity{};
    EndOfStreamPublicStatus status{EndOfStreamPublicStatus::Unknown};

    bool operator==(const EndOfStreamPublicOutcome& other) const = default;
};

} // namespace kivo::playback::end_of_stream_public
