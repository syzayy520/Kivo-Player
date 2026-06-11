#pragma once

#include "../identity/p2_public_surface_retention_audit_identity.h"
#include "p2_public_surface_retention_audit_status.h"

namespace kivo::playback::p2_public_surface_retention_audit {

struct P2PublicSurfaceRetentionAuditOutcome {
    P2PublicSurfaceRetentionAuditIdentity identity{};
    P2PublicSurfaceRetentionAuditStatus status{P2PublicSurfaceRetentionAuditStatus::Unknown};

    bool operator==(const P2PublicSurfaceRetentionAuditOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_retention_audit
