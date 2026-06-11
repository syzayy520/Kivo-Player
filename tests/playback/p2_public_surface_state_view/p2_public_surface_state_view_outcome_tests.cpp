#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_state_view/outcome/p2_public_surface_state_view_outcome.h"
#include "playback/p2_public_surface_state_view/outcome/p2_public_surface_state_view_rejection_reason.h"
#include "playback/p2_public_surface_state_view/outcome/p2_public_surface_state_view_drop_reason.h"

using namespace kivo::playback::p2_public_surface_state_view;

void test_p2_public_surface_state_view_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStateViewStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStateViewStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStateViewStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStateViewStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStateViewRejectionReason::ClosureAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStateViewRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStateViewRejectionReason::ViewIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStateViewRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStateViewDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStateViewDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStateViewDropReason::Unknown) == 2);
    P2PublicSurfaceStateViewOutcome outcome{};
    assert(outcome.identity.view_id.value == 0);
    assert(outcome.status == P2PublicSurfaceStateViewStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_state_view_outcome_default_construction" << std::endl;
}
