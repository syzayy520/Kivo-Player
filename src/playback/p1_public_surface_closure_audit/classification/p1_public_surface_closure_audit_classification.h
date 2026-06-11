#pragma once

#include "p1_public_surface_closure_audit_kind.h"
#include "p1_public_surface_closure_audit_scope.h"

namespace kivo::playback::p1_public_surface_closure_audit {

struct P1PublicSurfaceClosureAuditClassification {
    P1PublicSurfaceClosureAuditKind kind{P1PublicSurfaceClosureAuditKind::Unknown};
    P1PublicSurfaceClosureAuditScope scope{P1PublicSurfaceClosureAuditScope::Unknown};

    bool operator==(const P1PublicSurfaceClosureAuditClassification& other) const = default;
};

} // namespace kivo::playback::p1_public_surface_closure_audit
