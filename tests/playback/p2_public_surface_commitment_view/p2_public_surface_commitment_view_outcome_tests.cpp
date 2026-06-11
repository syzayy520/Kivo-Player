#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_commitment_view/outcome/p2_public_surface_commitment_view_outcome.h"
#include "playback/p2_public_surface_commitment_view/outcome/p2_public_surface_commitment_view_rejection_reason.h"
#include "playback/p2_public_surface_commitment_view/outcome/p2_public_surface_commitment_view_drop_reason.h"

using namespace kivo::playback::p2_public_surface_commitment_view;

void test_p2_public_surface_commitment_view_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCommitmentViewStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCommitmentViewStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCommitmentViewStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCommitmentViewStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCommitmentViewRejectionReason::ActivationAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCommitmentViewRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCommitmentViewRejectionReason::ViewIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCommitmentViewRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCommitmentViewDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCommitmentViewDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCommitmentViewDropReason::Unknown) == 2);
    P2PublicSurfaceCommitmentViewOutcome outcome{};
    assert(outcome.identity.view_id.value == 0);
    assert(outcome.status == P2PublicSurfaceCommitmentViewStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_commitment_view_outcome_default_construction" << std::endl;
}
