#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_preservation_view/outcome/p2_public_surface_preservation_view_outcome.h"
#include "playback/p2_public_surface_preservation_view/outcome/p2_public_surface_preservation_view_rejection_reason.h"
#include "playback/p2_public_surface_preservation_view/outcome/p2_public_surface_preservation_view_defer_reason.h"

using namespace kivo::playback::p2_public_surface_preservation_view;

void test_p2_public_surface_preservation_view_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfacePreservationViewStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePreservationViewStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePreservationViewStatus::Deferred) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePreservationViewStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePreservationViewRejectionReason::CustodyAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePreservationViewRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePreservationViewRejectionReason::ViewIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePreservationViewRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePreservationViewDeferReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePreservationViewDeferReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePreservationViewDeferReason::Unknown) == 2);
    P2PublicSurfacePreservationViewOutcome outcome{};
    assert(outcome.identity.view_id.value == 0);
    assert(outcome.status == P2PublicSurfacePreservationViewStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_preservation_view_outcome_default_construction" << std::endl;
}
