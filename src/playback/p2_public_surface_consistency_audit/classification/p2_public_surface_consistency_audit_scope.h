#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_consistency_audit {

enum class P2PublicSurfaceConsistencyAuditScope : std::uint8_t {
    PublicSurface,
    ProgressViewBoundary,
    ConsistencyBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_consistency_audit
