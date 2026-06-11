#pragma once

#include "p2_public_surface_stability_audit_kind.h"
#include "p2_public_surface_stability_audit_scope.h"

namespace kivo::playback::p2_public_surface_stability_audit {

struct P2PublicSurfaceStabilityAuditClassification {
    P2PublicSurfaceStabilityAuditKind kind{P2PublicSurfaceStabilityAuditKind::Unknown};
    P2PublicSurfaceStabilityAuditScope scope{P2PublicSurfaceStabilityAuditScope::Unknown};

    bool operator==(const P2PublicSurfaceStabilityAuditClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_stability_audit
