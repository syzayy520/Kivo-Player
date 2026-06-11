#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_chain_closure_audit/identity/p2_public_surface_chain_closure_audit_identity.h"
#include "playback/p2_public_surface_chain_closure_audit/anchor/p2_public_surface_delta_chain_closure_audit_anchor.h"
#include "playback/p2_public_surface_chain_closure_audit/closure/playback_p2_public_surface_chain_closure_audit.h"
#include "playback/p2_public_surface_chain_closure_audit/outcome/p2_public_surface_chain_closure_audit_outcome.h"

using namespace kivo::playback::p2_public_surface_chain_closure_audit;

void test_p2_public_surface_chain_closure_audit_boundary_cross_family() {
    P2PublicSurfaceDeltaChainClosureAuditAnchor anchor{};
    anchor.delta_identity.delta_id = kivo::playback::p2_public_surface_delta::P2PublicSurfaceDeltaId{123};
    assert(anchor.delta_identity.delta_id.value == 123);
    PlaybackP2PublicSurfaceChainClosureAudit closure{
        .identity = P2PublicSurfaceChainClosureAuditIdentity{.audit_id = P2PublicSurfaceChainClosureAuditId{1}},
        .anchors = P2PublicSurfaceChainClosureAuditAnchorSet{.delta_anchor = anchor},
        .classification = P2PublicSurfaceChainClosureAuditClassification{.kind = P2PublicSurfaceChainClosureAuditKind::SurfaceChainClosed, .scope = P2PublicSurfaceChainClosureAuditScope::P2SurfaceChain}
    };
    assert(closure.identity.audit_id.value == 1);
    assert(closure.anchors.delta_anchor.delta_identity.delta_id.value == 123);
    assert(closure.classification.kind == P2PublicSurfaceChainClosureAuditKind::SurfaceChainClosed);
    assert(closure.classification.scope == P2PublicSurfaceChainClosureAuditScope::P2SurfaceChain);
    P2PublicSurfaceChainClosureAuditOutcome outcome{.identity = P2PublicSurfaceChainClosureAuditIdentity{.audit_id = P2PublicSurfaceChainClosureAuditId{42}}, .status = P2PublicSurfaceChainClosureAuditStatus::Recorded};
    assert(outcome.identity.audit_id.value == 42);
    assert(outcome.status == P2PublicSurfaceChainClosureAuditStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_chain_closure_audit_boundary_cross_family" << std::endl;
}
