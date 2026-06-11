#pragma once

#include "p2_public_surface_retention_audit_kind.h"
#include "p2_public_surface_retention_audit_scope.h"

namespace kivo::playback::p2_public_surface_retention_audit {

struct P2PublicSurfaceRetentionAuditClassification {
    P2PublicSurfaceRetentionAuditKind kind{P2PublicSurfaceRetentionAuditKind::Unknown};
    P2PublicSurfaceRetentionAuditScope scope{P2PublicSurfaceRetentionAuditScope::Unknown};

    bool operator==(const P2PublicSurfaceRetentionAuditClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_retention_audit
