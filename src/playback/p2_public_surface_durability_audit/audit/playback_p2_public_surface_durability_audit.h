#pragma once

#include "../identity/p2_public_surface_durability_audit_identity.h"
#include "../anchor/p2_public_surface_durability_audit_anchor_set.h"
#include "../classification/p2_public_surface_durability_audit_classification.h"

namespace kivo::playback::p2_public_surface_durability_audit {

struct PlaybackP2PublicSurfaceDurabilityAudit {
    P2PublicSurfaceDurabilityAuditIdentity identity{};
    P2PublicSurfaceDurabilityAuditAnchorSet anchors{};
    P2PublicSurfaceDurabilityAuditClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_durability_audit
