#pragma once

#include "p2_public_surface_integrity_audit_kind.h"
#include "p2_public_surface_integrity_audit_scope.h"

namespace kivo::playback::p2_public_surface_integrity_audit {

struct P2PublicSurfaceIntegrityAuditClassification {
    P2PublicSurfaceIntegrityAuditKind kind{P2PublicSurfaceIntegrityAuditKind::Unknown};
    P2PublicSurfaceIntegrityAuditScope scope{P2PublicSurfaceIntegrityAuditScope::Unknown};

    bool operator==(const P2PublicSurfaceIntegrityAuditClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_integrity_audit
