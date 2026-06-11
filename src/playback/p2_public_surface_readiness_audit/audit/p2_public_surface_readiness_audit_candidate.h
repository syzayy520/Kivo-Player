#pragma once

#include "../identity/p2_public_surface_readiness_audit_identity.h"
#include "../anchor/p2_public_surface_readiness_audit_anchor_set.h"
#include "../classification/p2_public_surface_readiness_audit_classification.h"

namespace kivo::playback::p2_public_surface_readiness_audit {

struct P2PublicSurfaceReadinessAuditCandidate {
    P2PublicSurfaceReadinessAuditIdentity identity{};
    P2PublicSurfaceReadinessAuditAnchorSet anchors{};
    P2PublicSurfaceReadinessAuditClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_readiness_audit
