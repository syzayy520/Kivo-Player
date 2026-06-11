#pragma once

#include "../identity/p2_public_surface_stability_audit_identity.h"
#include "p2_public_surface_stability_audit_status.h"

namespace kivo::playback::p2_public_surface_stability_audit {

struct P2PublicSurfaceStabilityAuditOutcome {
    P2PublicSurfaceStabilityAuditIdentity identity{};
    P2PublicSurfaceStabilityAuditStatus status{P2PublicSurfaceStabilityAuditStatus::Unknown};

    bool operator==(const P2PublicSurfaceStabilityAuditOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_stability_audit
