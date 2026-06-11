#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_retention_audit {

enum class P2PublicSurfaceRetentionAuditDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_retention_audit
