#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_progress_view/outcome/p2_public_surface_progress_view_outcome.h"
#include "playback/p2_public_surface_progress_view/outcome/p2_public_surface_progress_view_rejection_reason.h"
#include "playback/p2_public_surface_progress_view/outcome/p2_public_surface_progress_view_drop_reason.h"

using namespace kivo::playback::p2_public_surface_progress_view;

void test_p2_public_surface_progress_view_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceProgressViewStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceProgressViewStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceProgressViewStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceProgressViewStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceProgressViewRejectionReason::StateViewAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceProgressViewRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceProgressViewRejectionReason::ViewIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceProgressViewRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceProgressViewDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceProgressViewDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceProgressViewDropReason::Unknown) == 2);
    P2PublicSurfaceProgressViewOutcome outcome{};
    assert(outcome.identity.view_id.value == 0);
    assert(outcome.status == P2PublicSurfaceProgressViewStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_progress_view_outcome_default_construction" << std::endl;
}
