#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_consistency_audit/classification/p2_public_surface_consistency_audit_classification.h"

using namespace kivo::playback::p2_public_surface_consistency_audit;

void test_p2_public_surface_consistency_audit_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConsistencyAuditKind::ProgressConsistent) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConsistencyAuditKind::SurfaceConsistent) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConsistencyAuditKind::ProofOnly) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConsistencyAuditKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConsistencyAuditScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConsistencyAuditScope::ProgressViewBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConsistencyAuditScope::ConsistencyBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConsistencyAuditScope::Unknown) == 3);
    P2PublicSurfaceConsistencyAuditClassification classification{};
    assert(classification.kind == P2PublicSurfaceConsistencyAuditKind::Unknown);
    assert(classification.scope == P2PublicSurfaceConsistencyAuditScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_consistency_audit_classification_default_construction" << std::endl;
}
