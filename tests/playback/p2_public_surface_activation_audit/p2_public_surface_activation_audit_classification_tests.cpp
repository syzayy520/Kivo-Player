#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_activation_audit/classification/p2_public_surface_activation_audit_classification.h"

using namespace kivo::playback::p2_public_surface_activation_audit;

void test_p2_public_surface_activation_audit_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationAuditKind::ActivationClosed) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationAuditKind::SurfaceActive) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationAuditKind::ProofOnly) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationAuditKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationAuditScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationAuditScope::ActivationBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationAuditScope::AuditBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationAuditScope::Unknown) == 3);
    P2PublicSurfaceActivationAuditClassification classification{};
    assert(classification.kind == P2PublicSurfaceActivationAuditKind::Unknown);
    assert(classification.scope == P2PublicSurfaceActivationAuditScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_activation_audit_classification_default_construction" << std::endl;
}
