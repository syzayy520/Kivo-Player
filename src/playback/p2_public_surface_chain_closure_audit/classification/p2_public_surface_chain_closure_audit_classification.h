#pragma once

#include "p2_public_surface_chain_closure_audit_kind.h"
#include "p2_public_surface_chain_closure_audit_scope.h"

namespace kivo::playback::p2_public_surface_chain_closure_audit {

struct P2PublicSurfaceChainClosureAuditClassification {
    P2PublicSurfaceChainClosureAuditKind kind{P2PublicSurfaceChainClosureAuditKind::Unknown};
    P2PublicSurfaceChainClosureAuditScope scope{P2PublicSurfaceChainClosureAuditScope::Unknown};

    bool operator==(const P2PublicSurfaceChainClosureAuditClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_chain_closure_audit
