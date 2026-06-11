#pragma once

#include "../identity/p2_public_surface_stability_audit_identity.h"
#include "../anchor/p2_public_surface_stability_audit_anchor_set.h"
#include "../classification/p2_public_surface_stability_audit_classification.h"

namespace kivo::playback::p2_public_surface_stability_audit {

struct PlaybackP2PublicSurfaceStabilityAudit {
    P2PublicSurfaceStabilityAuditIdentity identity{};
    P2PublicSurfaceStabilityAuditAnchorSet anchors{};
    P2PublicSurfaceStabilityAuditClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_stability_audit
