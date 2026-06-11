#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_readiness_audit {

struct P2PublicSurfaceReadinessAuditSequenceId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceReadinessAuditSequenceId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_readiness_audit
