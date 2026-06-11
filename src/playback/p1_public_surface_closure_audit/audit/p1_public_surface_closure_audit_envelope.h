#pragma once

#include "../identity/p1_public_surface_closure_audit_identity.h"
#include "../anchor/p1_public_surface_closure_audit_anchor_set.h"
#include "../classification/p1_public_surface_closure_audit_classification.h"

namespace kivo::playback::p1_public_surface_closure_audit {

struct P1PublicSurfaceClosureAuditEnvelope {
    P1PublicSurfaceClosureAuditIdentity identity{};
    P1PublicSurfaceClosureAuditAnchorSet anchors{};
    P1PublicSurfaceClosureAuditClassification classification{};
};

} // namespace kivo::playback::p1_public_surface_closure_audit
