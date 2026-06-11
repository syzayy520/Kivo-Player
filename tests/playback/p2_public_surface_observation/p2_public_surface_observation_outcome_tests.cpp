#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_observation/outcome/p2_public_surface_observation_outcome.h"
#include "playback/p2_public_surface_observation/outcome/p2_public_surface_observation_rejection_reason.h"
#include "playback/p2_public_surface_observation/outcome/p2_public_surface_observation_drop_reason.h"

using namespace kivo::playback::p2_public_surface_observation;

void test_p2_public_surface_observation_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceObservationStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceObservationStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceObservationStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceObservationStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceObservationRejectionReason::AuditAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceObservationRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceObservationRejectionReason::ObservationIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceObservationRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceObservationDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceObservationDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceObservationDropReason::Unknown) == 2);
    P2PublicSurfaceObservationOutcome outcome{};
    assert(outcome.identity.observation_id.value == 0);
    assert(outcome.status == P2PublicSurfaceObservationStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_observation_outcome_default_construction" << std::endl;
}
