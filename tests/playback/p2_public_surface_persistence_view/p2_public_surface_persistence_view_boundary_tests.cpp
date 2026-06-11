#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_persistence_view/identity/p2_public_surface_persistence_view_identity.h"
#include "playback/p2_public_surface_persistence_view/anchor/p2_public_surface_durability_persistence_view_anchor.h"
#include "playback/p2_public_surface_persistence_view/persistence_view/playback_p2_public_surface_persistence_view.h"
#include "playback/p2_public_surface_persistence_view/outcome/p2_public_surface_persistence_view_outcome.h"

using namespace kivo::playback::p2_public_surface_persistence_view;

void test_p2_public_surface_persistence_view_boundary_cross_family() {
    P2PublicSurfaceDurabilityPersistenceViewAnchor anchor{};
    anchor.durability_identity.audit_id = kivo::playback::p2_public_surface_durability_audit::P2PublicSurfaceDurabilityAuditId{123};
    assert(anchor.durability_identity.audit_id.value == 123);
    PlaybackP2PublicSurfacePersistenceView view{
        .identity = P2PublicSurfacePersistenceViewIdentity{.view_id = P2PublicSurfacePersistenceViewId{1}},
        .anchors = P2PublicSurfacePersistenceViewAnchorSet{.durability_anchor = anchor},
        .classification = P2PublicSurfacePersistenceViewClassification{.kind = P2PublicSurfacePersistenceViewKind::SurfacePersistent, .scope = P2PublicSurfacePersistenceViewScope::PersistenceBoundary}
    };
    assert(view.identity.view_id.value == 1);
    assert(view.anchors.durability_anchor.durability_identity.audit_id.value == 123);
    assert(view.classification.kind == P2PublicSurfacePersistenceViewKind::SurfacePersistent);
    assert(view.classification.scope == P2PublicSurfacePersistenceViewScope::PersistenceBoundary);
    P2PublicSurfacePersistenceViewOutcome outcome{.identity = P2PublicSurfacePersistenceViewIdentity{.view_id = P2PublicSurfacePersistenceViewId{42}}, .status = P2PublicSurfacePersistenceViewStatus::Recorded};
    assert(outcome.identity.view_id.value == 42);
    assert(outcome.status == P2PublicSurfacePersistenceViewStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_persistence_view_boundary_cross_family" << std::endl;
}
