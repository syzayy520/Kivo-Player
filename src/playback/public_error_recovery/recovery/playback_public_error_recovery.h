#pragma once

#include "../identity/public_error_recovery_identity.h"
#include "../anchor/public_error_recovery_anchor_set.h"
#include "../classification/public_error_recovery_classification.h"

namespace kivo::playback::public_error_recovery {

struct PlaybackPublicErrorRecovery {
    PublicErrorRecoveryIdentity identity{};
    PublicErrorRecoveryAnchorSet anchors{};
    PublicErrorRecoveryClassification classification{};
};

} // namespace kivo::playback::public_error_recovery
