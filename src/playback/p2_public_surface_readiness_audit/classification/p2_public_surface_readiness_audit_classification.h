#pragma once

#include "p2_public_surface_readiness_audit_kind.h"
#include "p2_public_surface_readiness_audit_scope.h"

namespace kivo::playback::p2_public_surface_readiness_audit {

struct P2PublicSurfaceReadinessAuditClassification {
    P2PublicSurfaceReadinessAuditKind kind{P2PublicSurfaceReadinessAuditKind::Unknown};
    P2PublicSurfaceReadinessAuditScope scope{P2PublicSurfaceReadinessAuditScope::Unknown};

    bool operator==(const P2PublicSurfaceReadinessAuditClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_readiness_audit
