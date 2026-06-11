#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_coherence_view/identity/p2_public_surface_coherence_view_identity.h"
#include "playback/p2_public_surface_coherence_view/anchor/p2_public_surface_integrity_coherence_view_anchor.h"
#include "playback/p2_public_surface_coherence_view/coherence_view/playback_p2_public_surface_coherence_view.h"
#include "playback/p2_public_surface_coherence_view/outcome/p2_public_surface_coherence_view_outcome.h"

using namespace kivo::playback::p2_public_surface_coherence_view;

void test_p2_public_surface_coherence_view_boundary_cross_family() {
    P2PublicSurfaceIntegrityCoherenceViewAnchor anchor{};
    anchor.integrity_identity.audit_id = kivo::playback::p2_public_surface_integrity_audit::P2PublicSurfaceIntegrityAuditId{123};
    assert(anchor.integrity_identity.audit_id.value == 123);
    PlaybackP2PublicSurfaceCoherenceView view{
        .identity = P2PublicSurfaceCoherenceViewIdentity{.view_id = P2PublicSurfaceCoherenceViewId{1}},
        .anchors = P2PublicSurfaceCoherenceViewAnchorSet{.integrity_anchor = anchor},
        .classification = P2PublicSurfaceCoherenceViewClassification{.kind = P2PublicSurfaceCoherenceViewKind::SurfaceCoherent, .scope = P2PublicSurfaceCoherenceViewScope::CoherenceBoundary}
    };
    assert(view.identity.view_id.value == 1);
    assert(view.anchors.integrity_anchor.integrity_identity.audit_id.value == 123);
    assert(view.classification.kind == P2PublicSurfaceCoherenceViewKind::SurfaceCoherent);
    assert(view.classification.scope == P2PublicSurfaceCoherenceViewScope::CoherenceBoundary);
    P2PublicSurfaceCoherenceViewOutcome outcome{.identity = P2PublicSurfaceCoherenceViewIdentity{.view_id = P2PublicSurfaceCoherenceViewId{42}}, .status = P2PublicSurfaceCoherenceViewStatus::Recorded};
    assert(outcome.identity.view_id.value == 42);
    assert(outcome.status == P2PublicSurfaceCoherenceViewStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_coherence_view_boundary_cross_family" << std::endl;
}
