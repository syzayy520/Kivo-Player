#pragma once

#include "playback/p2_public_surface_chain_closure_audit/identity/p2_public_surface_chain_closure_audit_identity.h"

namespace kivo::playback::p2_public_surface_state_view {

struct P2PublicSurfaceChainClosureStateViewAnchor {
    kivo::playback::p2_public_surface_chain_closure_audit::P2PublicSurfaceChainClosureAuditIdentity closure_identity{};
};

} // namespace kivo::playback::p2_public_surface_state_view
