#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_chain_closure_audit/classification/p2_public_surface_chain_closure_audit_classification.h"

using namespace kivo::playback::p2_public_surface_chain_closure_audit;

void test_p2_public_surface_chain_closure_audit_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceChainClosureAuditKind::DeltaClosed) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceChainClosureAuditKind::SurfaceChainClosed) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceChainClosureAuditKind::ProofOnly) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceChainClosureAuditKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceChainClosureAuditScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceChainClosureAuditScope::DeltaBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceChainClosureAuditScope::P2SurfaceChain) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceChainClosureAuditScope::Unknown) == 3);
    P2PublicSurfaceChainClosureAuditClassification classification{};
    assert(classification.kind == P2PublicSurfaceChainClosureAuditKind::Unknown);
    assert(classification.scope == P2PublicSurfaceChainClosureAuditScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_chain_closure_audit_classification_default_construction" << std::endl;
}
