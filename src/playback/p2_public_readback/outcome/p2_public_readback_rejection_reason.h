#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_readback {

enum class P2PublicReadbackRejectionReason : std::uint8_t {
    AdmissionAnchorMissing,
    ClassificationInvalid,
    ReadbackIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_readback
