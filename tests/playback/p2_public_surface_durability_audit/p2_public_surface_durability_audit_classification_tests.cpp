#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_durability_audit/classification/p2_public_surface_durability_audit_classification.h"

using namespace kivo::playback::p2_public_surface_durability_audit;

void test_p2_public_surface_durability_audit_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityAuditKind::DurabilityClosed) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityAuditKind::SurfaceDurable) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityAuditKind::ProofOnly) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityAuditKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityAuditScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityAuditScope::DurabilityBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityAuditScope::AuditBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityAuditScope::Unknown) == 3);
    P2PublicSurfaceDurabilityAuditClassification classification{};
    assert(classification.kind == P2PublicSurfaceDurabilityAuditKind::Unknown);
    assert(classification.scope == P2PublicSurfaceDurabilityAuditScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_durability_audit_classification_default_construction" << std::endl;
}
