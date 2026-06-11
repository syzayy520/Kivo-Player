#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_observation/observation/playback_p2_public_surface_observation.h"
#include "playback/p2_public_surface_observation/observation/p2_public_surface_observation_candidate.h"
#include "playback/p2_public_surface_observation/observation/p2_public_surface_observation_envelope.h"
#include "playback/p2_public_surface_observation/observation/p2_public_surface_observation_record.h"

using namespace kivo::playback::p2_public_surface_observation;

void test_p2_public_surface_observation_observation_default_construction() {
    P2PublicSurfaceObservationCandidate candidate{};
    assert(candidate.identity.observation_id.value == 0);
    assert(candidate.anchors.audit_anchor.audit_identity.audit_id.value == 0);
    assert(candidate.classification.kind == P2PublicSurfaceObservationKind::Unknown);
    PlaybackP2PublicSurfaceObservation observation{};
    assert(observation.identity.observation_id.value == 0);
    P2PublicSurfaceObservationEnvelope envelope{};
    assert(envelope.identity.observation_id.value == 0);
    P2PublicSurfaceObservationRecord record{};
    assert(record.envelope.identity.observation_id.value == 0);
    assert(record.observation.identity.observation_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_observation_observation_default_construction" << std::endl;
}
