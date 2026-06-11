#pragma once

#include "../identity/p2_public_surface_chain_closure_audit_identity.h"
#include "p2_public_surface_chain_closure_audit_status.h"

namespace kivo::playback::p2_public_surface_chain_closure_audit {

struct P2PublicSurfaceChainClosureAuditOutcome {
    P2PublicSurfaceChainClosureAuditIdentity identity{};
    P2PublicSurfaceChainClosureAuditStatus status{P2PublicSurfaceChainClosureAuditStatus::Unknown};

    bool operator==(const P2PublicSurfaceChainClosureAuditOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_chain_closure_audit
