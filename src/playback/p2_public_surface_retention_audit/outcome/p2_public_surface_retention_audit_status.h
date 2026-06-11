#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_retention_audit {

enum class P2PublicSurfaceRetentionAuditStatus : std::uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_retention_audit
