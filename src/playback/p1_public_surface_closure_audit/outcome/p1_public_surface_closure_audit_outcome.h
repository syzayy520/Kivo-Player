#pragma once

#include "../identity/p1_public_surface_closure_audit_identity.h"
#include "p1_public_surface_closure_audit_status.h"

namespace kivo::playback::p1_public_surface_closure_audit {

struct P1PublicSurfaceClosureAuditOutcome {
    P1PublicSurfaceClosureAuditIdentity identity{};
    P1PublicSurfaceClosureAuditStatus status{P1PublicSurfaceClosureAuditStatus::Unknown};

    bool operator==(const P1PublicSurfaceClosureAuditOutcome& other) const = default;
};

} // namespace kivo::playback::p1_public_surface_closure_audit
