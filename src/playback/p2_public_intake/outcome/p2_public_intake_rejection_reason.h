#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_intake {

enum class P2PublicIntakeRejectionReason : std::uint8_t {
    ClosureAnchorMissing,
    ClassificationInvalid,
    IntakeIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_intake
