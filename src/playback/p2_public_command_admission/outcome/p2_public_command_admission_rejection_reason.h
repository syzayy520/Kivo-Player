#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_command_admission {

enum class P2PublicCommandAdmissionRejectionReason : std::uint8_t {
    IntakeAnchorMissing,
    ClassificationInvalid,
    AdmissionIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_command_admission
