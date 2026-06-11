#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_stability_audit/classification/p2_public_surface_stability_audit_classification.h"

using namespace kivo::playback::p2_public_surface_stability_audit;

void test_p2_public_surface_stability_audit_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityAuditKind::StabilityClosed) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityAuditKind::SurfaceStable) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityAuditKind::ProofOnly) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityAuditKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityAuditScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityAuditScope::StabilityBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityAuditScope::AuditBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityAuditScope::Unknown) == 3);
    P2PublicSurfaceStabilityAuditClassification classification{};
    assert(classification.kind == P2PublicSurfaceStabilityAuditKind::Unknown);
    assert(classification.scope == P2PublicSurfaceStabilityAuditScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_stability_audit_classification_default_construction" << std::endl;
}
