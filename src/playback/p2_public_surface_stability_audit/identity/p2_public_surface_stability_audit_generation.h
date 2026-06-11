#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_stability_audit {

struct P2PublicSurfaceStabilityAuditGeneration {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceStabilityAuditGeneration& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_stability_audit
