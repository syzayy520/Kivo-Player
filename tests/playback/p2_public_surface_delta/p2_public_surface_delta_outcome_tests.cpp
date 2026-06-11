#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_delta/outcome/p2_public_surface_delta_outcome.h"
#include "playback/p2_public_surface_delta/outcome/p2_public_surface_delta_rejection_reason.h"
#include "playback/p2_public_surface_delta/outcome/p2_public_surface_delta_drop_reason.h"

using namespace kivo::playback::p2_public_surface_delta;

void test_p2_public_surface_delta_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDeltaStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDeltaStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDeltaStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDeltaStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDeltaRejectionReason::SnapshotAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDeltaRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDeltaRejectionReason::DeltaIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDeltaRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDeltaDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDeltaDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDeltaDropReason::Unknown) == 2);
    P2PublicSurfaceDeltaOutcome outcome{};
    assert(outcome.identity.delta_id.value == 0);
    assert(outcome.status == P2PublicSurfaceDeltaStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_delta_outcome_default_construction" << std::endl;
}
