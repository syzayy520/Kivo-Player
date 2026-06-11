#pragma once

#include "public_error_recovery_id.h"
#include "public_error_recovery_sequence_id.h"
#include "public_error_recovery_generation.h"

namespace kivo::playback::public_error_recovery {

struct PublicErrorRecoveryIdentity {
    PublicErrorRecoveryId recovery_id{};
    PublicErrorRecoverySequenceId sequence_id{};
    PublicErrorRecoveryGeneration generation{};

    bool operator==(const PublicErrorRecoveryIdentity& other) const = default;
};

} // namespace kivo::playback::public_error_recovery
