#pragma once

#include "playback/p2_public_surface_delta/identity/p2_public_surface_delta_identity.h"

namespace kivo::playback::p2_public_surface_chain_closure_audit {

struct P2PublicSurfaceDeltaChainClosureAuditAnchor {
    kivo::playback::p2_public_surface_delta::P2PublicSurfaceDeltaIdentity delta_identity{};
};

} // namespace kivo::playback::p2_public_surface_chain_closure_audit
