#pragma once

#include "p2_public_surface_chain_closure_audit_id.h"
#include "p2_public_surface_chain_closure_audit_sequence_id.h"
#include "p2_public_surface_chain_closure_audit_generation.h"

namespace kivo::playback::p2_public_surface_chain_closure_audit {

struct P2PublicSurfaceChainClosureAuditIdentity {
    P2PublicSurfaceChainClosureAuditId audit_id{};
    P2PublicSurfaceChainClosureAuditSequenceId sequence_id{};
    P2PublicSurfaceChainClosureAuditGeneration generation{};

    bool operator==(const P2PublicSurfaceChainClosureAuditIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_chain_closure_audit
