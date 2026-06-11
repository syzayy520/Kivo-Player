#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_chain_closure_audit/closure/playback_p2_public_surface_chain_closure_audit.h"
#include "playback/p2_public_surface_chain_closure_audit/closure/p2_public_surface_chain_closure_audit_candidate.h"
#include "playback/p2_public_surface_chain_closure_audit/closure/p2_public_surface_chain_closure_audit_envelope.h"
#include "playback/p2_public_surface_chain_closure_audit/closure/p2_public_surface_chain_closure_audit_record.h"

using namespace kivo::playback::p2_public_surface_chain_closure_audit;

void test_p2_public_surface_chain_closure_audit_closure_default_construction() {
    P2PublicSurfaceChainClosureAuditCandidate candidate{};
    assert(candidate.identity.audit_id.value == 0);
    assert(candidate.anchors.delta_anchor.delta_identity.delta_id.value == 0);
    assert(candidate.classification.kind == P2PublicSurfaceChainClosureAuditKind::Unknown);
    PlaybackP2PublicSurfaceChainClosureAudit closure{};
    assert(closure.identity.audit_id.value == 0);
    P2PublicSurfaceChainClosureAuditEnvelope envelope{};
    assert(envelope.identity.audit_id.value == 0);
    P2PublicSurfaceChainClosureAuditRecord record{};
    assert(record.envelope.identity.audit_id.value == 0);
    assert(record.closure.identity.audit_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_chain_closure_audit_closure_default_construction" << std::endl;
}
