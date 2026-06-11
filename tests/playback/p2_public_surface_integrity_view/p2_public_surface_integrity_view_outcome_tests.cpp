#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_integrity_view/outcome/p2_public_surface_integrity_view_outcome.h"
#include "playback/p2_public_surface_integrity_view/outcome/p2_public_surface_integrity_view_rejection_reason.h"
#include "playback/p2_public_surface_integrity_view/outcome/p2_public_surface_integrity_view_drop_reason.h"

using namespace kivo::playback::p2_public_surface_integrity_view;

void test_p2_public_surface_integrity_view_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityViewStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityViewStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityViewStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityViewStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityViewRejectionReason::ValidationAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityViewRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityViewRejectionReason::ViewIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityViewRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityViewDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityViewDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityViewDropReason::Unknown) == 2);
    P2PublicSurfaceIntegrityViewOutcome outcome{};
    assert(outcome.identity.view_id.value == 0);
    assert(outcome.status == P2PublicSurfaceIntegrityViewStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_integrity_view_outcome_default_construction" << std::endl;
}
