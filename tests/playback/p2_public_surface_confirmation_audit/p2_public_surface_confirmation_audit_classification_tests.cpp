#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_confirmation_audit/classification/p2_public_surface_confirmation_audit_classification.h"

using namespace kivo::playback::p2_public_surface_confirmation_audit;

void test_p2_public_surface_confirmation_audit_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationAuditKind::ConfirmationClosed) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationAuditKind::SurfaceConfirmed) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationAuditKind::ProofOnly) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationAuditKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationAuditScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationAuditScope::ConfirmationBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationAuditScope::AuditBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationAuditScope::Unknown) == 3);
    P2PublicSurfaceConfirmationAuditClassification classification{};
    assert(classification.kind == P2PublicSurfaceConfirmationAuditKind::Unknown);
    assert(classification.scope == P2PublicSurfaceConfirmationAuditScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_confirmation_audit_classification_default_construction" << std::endl;
}
