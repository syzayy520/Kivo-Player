#pragma once

#include "../identity/p2_public_surface_confirmation_audit_identity.h"
#include "../anchor/p2_public_surface_confirmation_audit_anchor_set.h"
#include "../classification/p2_public_surface_confirmation_audit_classification.h"

namespace kivo::playback::p2_public_surface_confirmation_audit {

struct PlaybackP2PublicSurfaceConfirmationAudit {
    P2PublicSurfaceConfirmationAuditIdentity identity{};
    P2PublicSurfaceConfirmationAuditAnchorSet anchors{};
    P2PublicSurfaceConfirmationAuditClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_confirmation_audit
