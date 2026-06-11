#pragma once

#include "public_error_recovery_kind.h"
#include "public_error_recovery_scope.h"

namespace kivo::playback::public_error_recovery {

struct PublicErrorRecoveryClassification {
    PublicErrorRecoveryKind kind{PublicErrorRecoveryKind::Unknown};
    PublicErrorRecoveryScope scope{PublicErrorRecoveryScope::Unknown};

    bool operator==(const PublicErrorRecoveryClassification& other) const = default;
};

} // namespace kivo::playback::public_error_recovery
