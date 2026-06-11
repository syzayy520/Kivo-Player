#pragma once

#include "p2_public_surface_consistency_audit_kind.h"
#include "p2_public_surface_consistency_audit_scope.h"

namespace kivo::playback::p2_public_surface_consistency_audit {

struct P2PublicSurfaceConsistencyAuditClassification {
    P2PublicSurfaceConsistencyAuditKind kind{P2PublicSurfaceConsistencyAuditKind::Unknown};
    P2PublicSurfaceConsistencyAuditScope scope{P2PublicSurfaceConsistencyAuditScope::Unknown};

    bool operator==(const P2PublicSurfaceConsistencyAuditClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_consistency_audit
