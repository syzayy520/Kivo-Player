#pragma once

#include "../identity/p2_public_surface_readiness_audit_identity.h"
#include "p2_public_surface_readiness_audit_status.h"

namespace kivo::playback::p2_public_surface_readiness_audit {

struct P2PublicSurfaceReadinessAuditOutcome {
    P2PublicSurfaceReadinessAuditIdentity identity{};
    P2PublicSurfaceReadinessAuditStatus status{P2PublicSurfaceReadinessAuditStatus::Unknown};

    bool operator==(const P2PublicSurfaceReadinessAuditOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_readiness_audit
