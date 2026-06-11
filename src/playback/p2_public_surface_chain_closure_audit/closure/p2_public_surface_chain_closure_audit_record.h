#pragma once

#include "p2_public_surface_chain_closure_audit_envelope.h"
#include "playback_p2_public_surface_chain_closure_audit.h"

namespace kivo::playback::p2_public_surface_chain_closure_audit {

struct P2PublicSurfaceChainClosureAuditRecord {
    P2PublicSurfaceChainClosureAuditEnvelope envelope{};
    PlaybackP2PublicSurfaceChainClosureAudit closure{};
};

} // namespace kivo::playback::p2_public_surface_chain_closure_audit
