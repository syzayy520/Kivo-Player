#pragma once

#include "p2_public_surface_final_audit_kind.h"
#include "p2_public_surface_final_audit_scope.h"

namespace kivo::playback::p2_public_surface_final_audit {

struct P2PublicSurfaceFinalAuditClassification {
    P2PublicSurfaceFinalAuditKind kind{P2PublicSurfaceFinalAuditKind::Unknown};
    P2PublicSurfaceFinalAuditScope scope{P2PublicSurfaceFinalAuditScope::Unknown};

    bool operator==(const P2PublicSurfaceFinalAuditClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_final_audit
