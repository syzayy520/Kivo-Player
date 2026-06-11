#pragma once

#include "../identity/p2_public_surface_consistency_audit_identity.h"
#include "../anchor/p2_public_surface_consistency_audit_anchor_set.h"
#include "../classification/p2_public_surface_consistency_audit_classification.h"

namespace kivo::playback::p2_public_surface_consistency_audit {

struct PlaybackP2PublicSurfaceConsistencyAudit {
    P2PublicSurfaceConsistencyAuditIdentity identity{};
    P2PublicSurfaceConsistencyAuditAnchorSet anchors{};
    P2PublicSurfaceConsistencyAuditClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_consistency_audit
