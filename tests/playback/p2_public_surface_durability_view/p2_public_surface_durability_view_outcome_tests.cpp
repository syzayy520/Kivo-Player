#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_durability_view/outcome/p2_public_surface_durability_view_outcome.h"
#include "playback/p2_public_surface_durability_view/outcome/p2_public_surface_durability_view_rejection_reason.h"
#include "playback/p2_public_surface_durability_view/outcome/p2_public_surface_durability_view_drop_reason.h"

using namespace kivo::playback::p2_public_surface_durability_view;

void test_p2_public_surface_durability_view_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityViewStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityViewStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityViewStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityViewStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityViewRejectionReason::ContinuityAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityViewRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityViewRejectionReason::ViewIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityViewRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityViewDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityViewDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityViewDropReason::Unknown) == 2);
    P2PublicSurfaceDurabilityViewOutcome outcome{};
    assert(outcome.identity.view_id.value == 0);
    assert(outcome.status == P2PublicSurfaceDurabilityViewStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_durability_view_outcome_default_construction" << std::endl;
}
