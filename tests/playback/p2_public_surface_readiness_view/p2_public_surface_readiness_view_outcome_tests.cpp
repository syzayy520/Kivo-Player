#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_readiness_view/outcome/p2_public_surface_readiness_view_outcome.h"
#include "playback/p2_public_surface_readiness_view/outcome/p2_public_surface_readiness_view_rejection_reason.h"
#include "playback/p2_public_surface_readiness_view/outcome/p2_public_surface_readiness_view_drop_reason.h"

using namespace kivo::playback::p2_public_surface_readiness_view;

void test_p2_public_surface_readiness_view_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessViewStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessViewStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessViewStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessViewStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessViewRejectionReason::AvailabilityAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessViewRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessViewRejectionReason::ViewIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessViewRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessViewDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessViewDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessViewDropReason::Unknown) == 2);
    P2PublicSurfaceReadinessViewOutcome outcome{};
    assert(outcome.identity.view_id.value == 0);
    assert(outcome.status == P2PublicSurfaceReadinessViewStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_readiness_view_outcome_default_construction" << std::endl;
}
