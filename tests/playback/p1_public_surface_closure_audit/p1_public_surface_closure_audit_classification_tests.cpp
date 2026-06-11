#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p1_public_surface_closure_audit/classification/p1_public_surface_closure_audit_classification.h"

using namespace kivo::playback::p1_public_surface_closure_audit;

void test_p1_public_surface_closure_audit_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P1PublicSurfaceClosureAuditKind::ChainClosed) == 0);
    assert(static_cast<std::uint8_t>(P1PublicSurfaceClosureAuditKind::SurfaceClosed) == 1);
    assert(static_cast<std::uint8_t>(P1PublicSurfaceClosureAuditKind::ProofOnly) == 2);
    assert(static_cast<std::uint8_t>(P1PublicSurfaceClosureAuditKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P1PublicSurfaceClosureAuditScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P1PublicSurfaceClosureAuditScope::P1Chain) == 1);
    assert(static_cast<std::uint8_t>(P1PublicSurfaceClosureAuditScope::Proof) == 2);
    assert(static_cast<std::uint8_t>(P1PublicSurfaceClosureAuditScope::Unknown) == 3);
    P1PublicSurfaceClosureAuditClassification classification{};
    assert(classification.kind == P1PublicSurfaceClosureAuditKind::Unknown);
    assert(classification.scope == P1PublicSurfaceClosureAuditScope::Unknown);
    std::cout << "PASS: test_p1_public_surface_closure_audit_classification_default_construction" << std::endl;
}
