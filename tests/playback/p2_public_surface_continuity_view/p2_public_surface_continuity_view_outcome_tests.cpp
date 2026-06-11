#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_continuity_view/outcome/p2_public_surface_continuity_view_outcome.h"
#include "playback/p2_public_surface_continuity_view/outcome/p2_public_surface_continuity_view_rejection_reason.h"
#include "playback/p2_public_surface_continuity_view/outcome/p2_public_surface_continuity_view_drop_reason.h"

using namespace kivo::playback::p2_public_surface_continuity_view;

void test_p2_public_surface_continuity_view_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceContinuityViewStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceContinuityViewStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceContinuityViewStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceContinuityViewStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceContinuityViewRejectionReason::StabilityAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceContinuityViewRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceContinuityViewRejectionReason::ViewIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceContinuityViewRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceContinuityViewDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceContinuityViewDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceContinuityViewDropReason::Unknown) == 2);
    P2PublicSurfaceContinuityViewOutcome outcome{};
    assert(outcome.identity.view_id.value == 0);
    assert(outcome.status == P2PublicSurfaceContinuityViewStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_continuity_view_outcome_default_construction" << std::endl;
}
