#pragma once

#include "end_of_stream_public_recovery_anchor.h"

namespace kivo::playback::public_error_recovery {

struct PublicErrorRecoveryAnchorSet {
    EndOfStreamPublicRecoveryAnchor end_anchor{};
};

} // namespace kivo::playback::public_error_recovery
