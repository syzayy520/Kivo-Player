#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_validation_view/outcome/p2_public_surface_validation_view_outcome.h"
#include "playback/p2_public_surface_validation_view/outcome/p2_public_surface_validation_view_rejection_reason.h"
#include "playback/p2_public_surface_validation_view/outcome/p2_public_surface_validation_view_drop_reason.h"

using namespace kivo::playback::p2_public_surface_validation_view;

void test_p2_public_surface_validation_view_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceValidationViewStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceValidationViewStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceValidationViewStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceValidationViewStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceValidationViewRejectionReason::ConfirmationAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceValidationViewRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceValidationViewRejectionReason::ViewIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceValidationViewRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceValidationViewDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceValidationViewDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceValidationViewDropReason::Unknown) == 2);
    P2PublicSurfaceValidationViewOutcome outcome{};
    assert(outcome.identity.view_id.value == 0);
    assert(outcome.status == P2PublicSurfaceValidationViewStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_validation_view_outcome_default_construction" << std::endl;
}
