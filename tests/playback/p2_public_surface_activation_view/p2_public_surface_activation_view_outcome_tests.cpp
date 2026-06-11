#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_activation_view/outcome/p2_public_surface_activation_view_outcome.h"
#include "playback/p2_public_surface_activation_view/outcome/p2_public_surface_activation_view_rejection_reason.h"
#include "playback/p2_public_surface_activation_view/outcome/p2_public_surface_activation_view_drop_reason.h"

using namespace kivo::playback::p2_public_surface_activation_view;

void test_p2_public_surface_activation_view_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationViewStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationViewStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationViewStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationViewStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationViewRejectionReason::EligibilityAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationViewRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationViewRejectionReason::ViewIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationViewRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationViewDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationViewDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationViewDropReason::Unknown) == 2);
    P2PublicSurfaceActivationViewOutcome outcome{};
    assert(outcome.identity.view_id.value == 0);
    assert(outcome.status == P2PublicSurfaceActivationViewStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_activation_view_outcome_default_construction" << std::endl;
}
