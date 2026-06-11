#pragma once

#include "playback/end_of_stream_public/identity/end_of_stream_public_identity.h"

namespace kivo::playback::public_error_recovery {

struct EndOfStreamPublicRecoveryAnchor {
    kivo::playback::end_of_stream_public::EndOfStreamPublicIdentity end_identity{};
};

} // namespace kivo::playback::public_error_recovery
