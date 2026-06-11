#pragma once

#include "../identity/public_error_recovery_identity.h"
#include "public_error_recovery_status.h"

namespace kivo::playback::public_error_recovery {

struct PublicErrorRecoveryOutcome {
    PublicErrorRecoveryIdentity identity{};
    PublicErrorRecoveryStatus status{PublicErrorRecoveryStatus::Unknown};

    bool operator==(const PublicErrorRecoveryOutcome& other) const = default;
};

} // namespace kivo::playback::public_error_recovery
