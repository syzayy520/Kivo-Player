#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_availability_view/outcome/p2_public_surface_availability_view_outcome.h"
#include "playback/p2_public_surface_availability_view/outcome/p2_public_surface_availability_view_rejection_reason.h"
#include "playback/p2_public_surface_availability_view/outcome/p2_public_surface_availability_view_drop_reason.h"

using namespace kivo::playback::p2_public_surface_availability_view;

void test_p2_public_surface_availability_view_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceAvailabilityViewStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceAvailabilityViewStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceAvailabilityViewStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceAvailabilityViewStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceAvailabilityViewRejectionReason::ConsistencyAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceAvailabilityViewRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceAvailabilityViewRejectionReason::ViewIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceAvailabilityViewRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceAvailabilityViewDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceAvailabilityViewDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceAvailabilityViewDropReason::Unknown) == 2);
    P2PublicSurfaceAvailabilityViewOutcome outcome{};
    assert(outcome.identity.view_id.value == 0);
    assert(outcome.status == P2PublicSurfaceAvailabilityViewStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_availability_view_outcome_default_construction" << std::endl;
}
