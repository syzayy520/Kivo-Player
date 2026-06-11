#pragma once

#include "public_error_recovery_envelope.h"
#include "playback_public_error_recovery.h"

namespace kivo::playback::public_error_recovery {

struct PublicErrorRecoveryRecord {
    PublicErrorRecoveryEnvelope envelope{};
    PlaybackPublicErrorRecovery recovery{};
};

} // namespace kivo::playback::public_error_recovery
