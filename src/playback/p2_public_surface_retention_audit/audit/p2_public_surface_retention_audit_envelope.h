#pragma once

#include "../identity/p2_public_surface_retention_audit_identity.h"
#include "../anchor/p2_public_surface_retention_audit_anchor_set.h"
#include "../classification/p2_public_surface_retention_audit_classification.h"

namespace kivo::playback::p2_public_surface_retention_audit {

struct P2PublicSurfaceRetentionAuditEnvelope {
    P2PublicSurfaceRetentionAuditIdentity identity{};
    P2PublicSurfaceRetentionAuditAnchorSet anchors{};
    P2PublicSurfaceRetentionAuditClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_retention_audit
