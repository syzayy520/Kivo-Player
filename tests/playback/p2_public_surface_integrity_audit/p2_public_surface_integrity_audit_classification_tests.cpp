#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_integrity_audit/classification/p2_public_surface_integrity_audit_classification.h"

using namespace kivo::playback::p2_public_surface_integrity_audit;

void test_p2_public_surface_integrity_audit_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityAuditKind::IntegrityClosed) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityAuditKind::SurfaceIntact) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityAuditKind::ProofOnly) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityAuditKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityAuditScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityAuditScope::IntegrityBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityAuditScope::AuditBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityAuditScope::Unknown) == 3);
    P2PublicSurfaceIntegrityAuditClassification classification{};
    assert(classification.kind == P2PublicSurfaceIntegrityAuditKind::Unknown);
    assert(classification.scope == P2PublicSurfaceIntegrityAuditScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_integrity_audit_classification_default_construction" << std::endl;
}
