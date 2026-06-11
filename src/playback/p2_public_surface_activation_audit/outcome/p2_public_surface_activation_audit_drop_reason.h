#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_activation_audit {

enum class P2PublicSurfaceActivationAuditDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_activation_audit
