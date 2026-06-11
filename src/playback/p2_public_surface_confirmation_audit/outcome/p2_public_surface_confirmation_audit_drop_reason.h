#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_confirmation_audit {

enum class P2PublicSurfaceConfirmationAuditDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_confirmation_audit
