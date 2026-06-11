#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_stability_audit {

struct P2PublicSurfaceStabilityAuditSequenceId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceStabilityAuditSequenceId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_stability_audit
