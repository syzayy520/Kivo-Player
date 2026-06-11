#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_observation/identity/p2_public_surface_observation_identity.h"
#include "playback/p2_public_surface_observation/anchor/p2_public_chain_audit_surface_observation_anchor.h"
#include "playback/p2_public_surface_observation/observation/playback_p2_public_surface_observation.h"
#include "playback/p2_public_surface_observation/outcome/p2_public_surface_observation_outcome.h"

using namespace kivo::playback::p2_public_surface_observation;

void test_p2_public_surface_observation_boundary_cross_family() {
    P2PublicChainAuditSurfaceObservationAnchor anchor{};
    anchor.audit_identity.audit_id = kivo::playback::p2_public_chain_audit::P2PublicChainAuditId{123};
    assert(anchor.audit_identity.audit_id.value == 123);
    PlaybackP2PublicSurfaceObservation observation{
        .identity = P2PublicSurfaceObservationIdentity{.observation_id = P2PublicSurfaceObservationId{1}},
        .anchors = P2PublicSurfaceObservationAnchorSet{.audit_anchor = anchor},
        .classification = P2PublicSurfaceObservationClassification{.kind = P2PublicSurfaceObservationKind::SurfaceObservation, .scope = P2PublicSurfaceObservationScope::ObservationBoundary}
    };
    assert(observation.identity.observation_id.value == 1);
    assert(observation.anchors.audit_anchor.audit_identity.audit_id.value == 123);
    assert(observation.classification.kind == P2PublicSurfaceObservationKind::SurfaceObservation);
    assert(observation.classification.scope == P2PublicSurfaceObservationScope::ObservationBoundary);
    P2PublicSurfaceObservationOutcome outcome{.identity = P2PublicSurfaceObservationIdentity{.observation_id = P2PublicSurfaceObservationId{42}}, .status = P2PublicSurfaceObservationStatus::Recorded};
    assert(outcome.identity.observation_id.value == 42);
    assert(outcome.status == P2PublicSurfaceObservationStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_observation_boundary_cross_family" << std::endl;
}
