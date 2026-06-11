#pragma once

#include "../identity/p2_public_surface_chain_closure_audit_identity.h"
#include "../anchor/p2_public_surface_chain_closure_audit_anchor_set.h"
#include "../classification/p2_public_surface_chain_closure_audit_classification.h"

namespace kivo::playback::p2_public_surface_chain_closure_audit {

struct P2PublicSurfaceChainClosureAuditCandidate {
    P2PublicSurfaceChainClosureAuditIdentity identity{};
    P2PublicSurfaceChainClosureAuditAnchorSet anchors{};
    P2PublicSurfaceChainClosureAuditClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_chain_closure_audit
