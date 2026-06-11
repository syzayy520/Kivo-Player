#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_eligibility_view/identity/p2_public_surface_eligibility_view_identity.h"
#include "playback/p2_public_surface_eligibility_view/anchor/p2_public_surface_readiness_eligibility_view_anchor.h"
#include "playback/p2_public_surface_eligibility_view/eligibility_view/playback_p2_public_surface_eligibility_view.h"
#include "playback/p2_public_surface_eligibility_view/outcome/p2_public_surface_eligibility_view_outcome.h"

using namespace kivo::playback::p2_public_surface_eligibility_view;

void test_p2_public_surface_eligibility_view_boundary_cross_family() {
    P2PublicSurfaceReadinessEligibilityViewAnchor anchor{};
    anchor.readiness_identity.audit_id = kivo::playback::p2_public_surface_readiness_audit::P2PublicSurfaceReadinessAuditId{123};
    assert(anchor.readiness_identity.audit_id.value == 123);
    PlaybackP2PublicSurfaceEligibilityView view{
        .identity = P2PublicSurfaceEligibilityViewIdentity{.view_id = P2PublicSurfaceEligibilityViewId{1}},
        .anchors = P2PublicSurfaceEligibilityViewAnchorSet{.readiness_anchor = anchor},
        .classification = P2PublicSurfaceEligibilityViewClassification{.kind = P2PublicSurfaceEligibilityViewKind::SurfaceEligible, .scope = P2PublicSurfaceEligibilityViewScope::EligibilityBoundary}
    };
    assert(view.identity.view_id.value == 1);
    assert(view.anchors.readiness_anchor.readiness_identity.audit_id.value == 123);
    assert(view.classification.kind == P2PublicSurfaceEligibilityViewKind::SurfaceEligible);
    assert(view.classification.scope == P2PublicSurfaceEligibilityViewScope::EligibilityBoundary);
    P2PublicSurfaceEligibilityViewOutcome outcome{.identity = P2PublicSurfaceEligibilityViewIdentity{.view_id = P2PublicSurfaceEligibilityViewId{42}}, .status = P2PublicSurfaceEligibilityViewStatus::Recorded};
    assert(outcome.identity.view_id.value == 42);
    assert(outcome.status == P2PublicSurfaceEligibilityViewStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_eligibility_view_boundary_cross_family" << std::endl;
}
