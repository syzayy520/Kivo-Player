#pragma once

#include "../identity/p2_public_surface_integrity_audit_identity.h"
#include "../anchor/p2_public_surface_integrity_audit_anchor_set.h"
#include "../classification/p2_public_surface_integrity_audit_classification.h"

namespace kivo::playback::p2_public_surface_integrity_audit {

struct P2PublicSurfaceIntegrityAuditEnvelope {
    P2PublicSurfaceIntegrityAuditIdentity identity{};
    P2PublicSurfaceIntegrityAuditAnchorSet anchors{};
    P2PublicSurfaceIntegrityAuditClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_integrity_audit
