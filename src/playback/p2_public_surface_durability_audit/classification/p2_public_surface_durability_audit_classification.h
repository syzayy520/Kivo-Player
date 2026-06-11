#pragma once

#include "p2_public_surface_durability_audit_kind.h"
#include "p2_public_surface_durability_audit_scope.h"

namespace kivo::playback::p2_public_surface_durability_audit {

struct P2PublicSurfaceDurabilityAuditClassification {
    P2PublicSurfaceDurabilityAuditKind kind{P2PublicSurfaceDurabilityAuditKind::Unknown};
    P2PublicSurfaceDurabilityAuditScope scope{P2PublicSurfaceDurabilityAuditScope::Unknown};

    bool operator==(const P2PublicSurfaceDurabilityAuditClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_durability_audit
