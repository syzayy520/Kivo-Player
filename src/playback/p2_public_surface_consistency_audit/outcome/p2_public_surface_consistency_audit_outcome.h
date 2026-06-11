#pragma once

#include "../identity/p2_public_surface_consistency_audit_identity.h"
#include "p2_public_surface_consistency_audit_status.h"

namespace kivo::playback::p2_public_surface_consistency_audit {

struct P2PublicSurfaceConsistencyAuditOutcome {
    P2PublicSurfaceConsistencyAuditIdentity identity{};
    P2PublicSurfaceConsistencyAuditStatus status{P2PublicSurfaceConsistencyAuditStatus::Unknown};

    bool operator==(const P2PublicSurfaceConsistencyAuditOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_consistency_audit
