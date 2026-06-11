#pragma once

#include "../identity/p2_public_surface_activation_audit_identity.h"
#include "../anchor/p2_public_surface_activation_audit_anchor_set.h"
#include "../classification/p2_public_surface_activation_audit_classification.h"

namespace kivo::playback::p2_public_surface_activation_audit {

struct PlaybackP2PublicSurfaceActivationAudit {
    P2PublicSurfaceActivationAuditIdentity identity{};
    P2PublicSurfaceActivationAuditAnchorSet anchors{};
    P2PublicSurfaceActivationAuditClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_activation_audit
