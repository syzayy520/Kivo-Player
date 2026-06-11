#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_integrity_audit {

enum class P2PublicSurfaceIntegrityAuditStatus : std::uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_integrity_audit
