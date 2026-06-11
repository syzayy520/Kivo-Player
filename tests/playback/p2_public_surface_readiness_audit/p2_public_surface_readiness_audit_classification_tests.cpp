#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_readiness_audit/classification/p2_public_surface_readiness_audit_classification.h"

using namespace kivo::playback::p2_public_surface_readiness_audit;

void test_p2_public_surface_readiness_audit_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessAuditKind::ReadinessClosed) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessAuditKind::SurfaceReady) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessAuditKind::ProofOnly) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessAuditKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessAuditScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessAuditScope::ReadinessBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessAuditScope::AuditBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessAuditScope::Unknown) == 3);
    P2PublicSurfaceReadinessAuditClassification classification{};
    assert(classification.kind == P2PublicSurfaceReadinessAuditKind::Unknown);
    assert(classification.scope == P2PublicSurfaceReadinessAuditScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_readiness_audit_classification_default_construction" << std::endl;
}
