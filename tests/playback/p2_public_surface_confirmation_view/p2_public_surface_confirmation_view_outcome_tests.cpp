#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_confirmation_view/outcome/p2_public_surface_confirmation_view_outcome.h"
#include "playback/p2_public_surface_confirmation_view/outcome/p2_public_surface_confirmation_view_rejection_reason.h"
#include "playback/p2_public_surface_confirmation_view/outcome/p2_public_surface_confirmation_view_drop_reason.h"

using namespace kivo::playback::p2_public_surface_confirmation_view;

void test_p2_public_surface_confirmation_view_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationViewStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationViewStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationViewStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationViewStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationViewRejectionReason::CommitmentAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationViewRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationViewRejectionReason::ViewIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationViewRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationViewDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationViewDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationViewDropReason::Unknown) == 2);
    P2PublicSurfaceConfirmationViewOutcome outcome{};
    assert(outcome.identity.view_id.value == 0);
    assert(outcome.status == P2PublicSurfaceConfirmationViewStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_confirmation_view_outcome_default_construction" << std::endl;
}
