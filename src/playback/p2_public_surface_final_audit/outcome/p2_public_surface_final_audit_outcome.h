#pragma once

#include "../identity/p2_public_surface_final_audit_identity.h"
#include "p2_public_surface_final_audit_status.h"

namespace kivo::playback::p2_public_surface_final_audit {

struct P2PublicSurfaceFinalAuditOutcome {
    P2PublicSurfaceFinalAuditIdentity identity{};
    P2PublicSurfaceFinalAuditStatus status{P2PublicSurfaceFinalAuditStatus::Unknown};

    bool operator==(const P2PublicSurfaceFinalAuditOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_final_audit
