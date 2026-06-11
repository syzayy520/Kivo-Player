#pragma once

#include "../identity/p2_public_surface_durability_audit_identity.h"
#include "p2_public_surface_durability_audit_status.h"

namespace kivo::playback::p2_public_surface_durability_audit {

struct P2PublicSurfaceDurabilityAuditOutcome {
    P2PublicSurfaceDurabilityAuditIdentity identity{};
    P2PublicSurfaceDurabilityAuditStatus status{P2PublicSurfaceDurabilityAuditStatus::Unknown};

    bool operator==(const P2PublicSurfaceDurabilityAuditOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_durability_audit
