#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_eligibility_view/outcome/p2_public_surface_eligibility_view_outcome.h"
#include "playback/p2_public_surface_eligibility_view/outcome/p2_public_surface_eligibility_view_rejection_reason.h"
#include "playback/p2_public_surface_eligibility_view/outcome/p2_public_surface_eligibility_view_drop_reason.h"

using namespace kivo::playback::p2_public_surface_eligibility_view;

void test_p2_public_surface_eligibility_view_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceEligibilityViewStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceEligibilityViewStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceEligibilityViewStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceEligibilityViewStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceEligibilityViewRejectionReason::ReadinessAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceEligibilityViewRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceEligibilityViewRejectionReason::ViewIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceEligibilityViewRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceEligibilityViewDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceEligibilityViewDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceEligibilityViewDropReason::Unknown) == 2);
    P2PublicSurfaceEligibilityViewOutcome outcome{};
    assert(outcome.identity.view_id.value == 0);
    assert(outcome.status == P2PublicSurfaceEligibilityViewStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_eligibility_view_outcome_default_construction" << std::endl;
}
