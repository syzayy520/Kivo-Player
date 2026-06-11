#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_retention_audit/classification/p2_public_surface_retention_audit_classification.h"

using namespace kivo::playback::p2_public_surface_retention_audit;

void test_p2_public_surface_retention_audit_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionAuditKind::RetentionClosed) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionAuditKind::SurfaceRetained) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionAuditKind::ProofOnly) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionAuditKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionAuditScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionAuditScope::RetentionBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionAuditScope::AuditBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionAuditScope::Unknown) == 3);
    P2PublicSurfaceRetentionAuditClassification classification{};
    assert(classification.kind == P2PublicSurfaceRetentionAuditKind::Unknown);
    assert(classification.scope == P2PublicSurfaceRetentionAuditScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_retention_audit_classification_default_construction" << std::endl;
}
