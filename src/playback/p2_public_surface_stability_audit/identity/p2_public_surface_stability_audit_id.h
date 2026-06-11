#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_stability_audit {

struct P2PublicSurfaceStabilityAuditId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceStabilityAuditId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_stability_audit
