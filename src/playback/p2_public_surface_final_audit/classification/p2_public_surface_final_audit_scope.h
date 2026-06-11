#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_final_audit {

enum class P2PublicSurfaceFinalAuditScope : std::uint8_t {
    PublicSurface,
    FinalBoundary,
    AuditBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_final_audit
