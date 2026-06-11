#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_availability_view/identity/p2_public_surface_availability_view_identity.h"
#include "playback/p2_public_surface_availability_view/anchor/p2_public_surface_consistency_availability_view_anchor.h"
#include "playback/p2_public_surface_availability_view/availability_view/playback_p2_public_surface_availability_view.h"
#include "playback/p2_public_surface_availability_view/outcome/p2_public_surface_availability_view_outcome.h"

using namespace kivo::playback::p2_public_surface_availability_view;

void test_p2_public_surface_availability_view_boundary_cross_family() {
    P2PublicSurfaceConsistencyAvailabilityViewAnchor anchor{};
    anchor.consistency_identity.audit_id = kivo::playback::p2_public_surface_consistency_audit::P2PublicSurfaceConsistencyAuditId{123};
    assert(anchor.consistency_identity.audit_id.value == 123);
    PlaybackP2PublicSurfaceAvailabilityView view{
        .identity = P2PublicSurfaceAvailabilityViewIdentity{.view_id = P2PublicSurfaceAvailabilityViewId{1}},
        .anchors = P2PublicSurfaceAvailabilityViewAnchorSet{.consistency_anchor = anchor},
        .classification = P2PublicSurfaceAvailabilityViewClassification{.kind = P2PublicSurfaceAvailabilityViewKind::SurfaceAvailable, .scope = P2PublicSurfaceAvailabilityViewScope::AvailabilityBoundary}
    };
    assert(view.identity.view_id.value == 1);
    assert(view.anchors.consistency_anchor.consistency_identity.audit_id.value == 123);
    assert(view.classification.kind == P2PublicSurfaceAvailabilityViewKind::SurfaceAvailable);
    assert(view.classification.scope == P2PublicSurfaceAvailabilityViewScope::AvailabilityBoundary);
    P2PublicSurfaceAvailabilityViewOutcome outcome{.identity = P2PublicSurfaceAvailabilityViewIdentity{.view_id = P2PublicSurfaceAvailabilityViewId{42}}, .status = P2PublicSurfaceAvailabilityViewStatus::Recorded};
    assert(outcome.identity.view_id.value == 42);
    assert(outcome.status == P2PublicSurfaceAvailabilityViewStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_availability_view_boundary_cross_family" << std::endl;
}
