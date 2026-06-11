#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_stability_view/outcome/p2_public_surface_stability_view_outcome.h"
#include "playback/p2_public_surface_stability_view/outcome/p2_public_surface_stability_view_rejection_reason.h"
#include "playback/p2_public_surface_stability_view/outcome/p2_public_surface_stability_view_drop_reason.h"

using namespace kivo::playback::p2_public_surface_stability_view;

void test_p2_public_surface_stability_view_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityViewStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityViewStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityViewStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityViewStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityViewRejectionReason::CoherenceAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityViewRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityViewRejectionReason::ViewIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityViewRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityViewDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityViewDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityViewDropReason::Unknown) == 2);
    P2PublicSurfaceStabilityViewOutcome outcome{};
    assert(outcome.identity.view_id.value == 0);
    assert(outcome.status == P2PublicSurfaceStabilityViewStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_stability_view_outcome_default_construction" << std::endl;
}
