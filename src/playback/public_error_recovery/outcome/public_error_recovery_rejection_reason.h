#pragma once

#include <cstdint>

namespace kivo::playback::public_error_recovery {

enum class PublicErrorRecoveryRejectionReason : std::uint8_t {
    EndOfStreamAnchorMissing,
    ClassificationInvalid,
    RecoveryIdentityMissing,
    Unknown
};

} // namespace kivo::playback::public_error_recovery
