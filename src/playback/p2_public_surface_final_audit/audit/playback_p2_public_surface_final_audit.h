#pragma once

#include "../identity/p2_public_surface_final_audit_identity.h"
#include "../anchor/p2_public_surface_final_audit_anchor_set.h"
#include "../classification/p2_public_surface_final_audit_classification.h"

namespace kivo::playback::p2_public_surface_final_audit {

struct PlaybackP2PublicSurfaceFinalAudit {
    P2PublicSurfaceFinalAuditIdentity identity{};
    P2PublicSurfaceFinalAuditAnchorSet anchors{};
    P2PublicSurfaceFinalAuditClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_final_audit
