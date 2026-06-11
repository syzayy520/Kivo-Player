#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_validation_view/identity/p2_public_surface_validation_view_identity.h"
#include "playback/p2_public_surface_validation_view/anchor/p2_public_surface_confirmation_validation_view_anchor.h"
#include "playback/p2_public_surface_validation_view/validation_view/playback_p2_public_surface_validation_view.h"
#include "playback/p2_public_surface_validation_view/outcome/p2_public_surface_validation_view_outcome.h"

using namespace kivo::playback::p2_public_surface_validation_view;

void test_p2_public_surface_validation_view_boundary_cross_family() {
    P2PublicSurfaceConfirmationValidationViewAnchor anchor{};
    anchor.confirmation_identity.audit_id = kivo::playback::p2_public_surface_confirmation_audit::P2PublicSurfaceConfirmationAuditId{123};
    assert(anchor.confirmation_identity.audit_id.value == 123);
    PlaybackP2PublicSurfaceValidationView view{
        .identity = P2PublicSurfaceValidationViewIdentity{.view_id = P2PublicSurfaceValidationViewId{1}},
        .anchors = P2PublicSurfaceValidationViewAnchorSet{.confirmation_anchor = anchor},
        .classification = P2PublicSurfaceValidationViewClassification{.kind = P2PublicSurfaceValidationViewKind::SurfaceValidated, .scope = P2PublicSurfaceValidationViewScope::ValidationBoundary}
    };
    assert(view.identity.view_id.value == 1);
    assert(view.anchors.confirmation_anchor.confirmation_identity.audit_id.value == 123);
    assert(view.classification.kind == P2PublicSurfaceValidationViewKind::SurfaceValidated);
    assert(view.classification.scope == P2PublicSurfaceValidationViewScope::ValidationBoundary);
    P2PublicSurfaceValidationViewOutcome outcome{.identity = P2PublicSurfaceValidationViewIdentity{.view_id = P2PublicSurfaceValidationViewId{42}}, .status = P2PublicSurfaceValidationViewStatus::Recorded};
    assert(outcome.identity.view_id.value == 42);
    assert(outcome.status == P2PublicSurfaceValidationViewStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_validation_view_boundary_cross_family" << std::endl;
}
