#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_final_audit/classification/p2_public_surface_final_audit_classification.h"

using namespace kivo::playback::p2_public_surface_final_audit;

void test_p2_public_surface_final_audit_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceFinalAuditKind::FinalClosed) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceFinalAuditKind::SurfaceFinalized) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceFinalAuditKind::ProofOnly) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceFinalAuditKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceFinalAuditScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceFinalAuditScope::FinalBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceFinalAuditScope::AuditBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceFinalAuditScope::Unknown) == 3);
    P2PublicSurfaceFinalAuditClassification classification{};
    assert(classification.kind == P2PublicSurfaceFinalAuditKind::Unknown);
    assert(classification.scope == P2PublicSurfaceFinalAuditScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_final_audit_classification_default_construction" << std::endl;
}
