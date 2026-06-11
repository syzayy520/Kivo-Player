#pragma once

#include "../identity/p2_public_surface_integrity_audit_identity.h"
#include "p2_public_surface_integrity_audit_status.h"

namespace kivo::playback::p2_public_surface_integrity_audit {

struct P2PublicSurfaceIntegrityAuditOutcome {
    P2PublicSurfaceIntegrityAuditIdentity identity{};
    P2PublicSurfaceIntegrityAuditStatus status{P2PublicSurfaceIntegrityAuditStatus::Unknown};

    bool operator==(const P2PublicSurfaceIntegrityAuditOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_integrity_audit
