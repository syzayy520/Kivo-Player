#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_confirmation_audit {

enum class P2PublicSurfaceConfirmationAuditStatus : std::uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_confirmation_audit
