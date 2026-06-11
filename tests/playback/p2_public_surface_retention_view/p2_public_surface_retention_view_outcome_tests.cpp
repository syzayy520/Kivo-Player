#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_retention_view/outcome/p2_public_surface_retention_view_outcome.h"
#include "playback/p2_public_surface_retention_view/outcome/p2_public_surface_retention_view_rejection_reason.h"
#include "playback/p2_public_surface_retention_view/outcome/p2_public_surface_retention_view_drop_reason.h"

using namespace kivo::playback::p2_public_surface_retention_view;

void test_p2_public_surface_retention_view_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionViewStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionViewStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionViewStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionViewStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionViewRejectionReason::PersistenceAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionViewRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionViewRejectionReason::ViewIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionViewRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionViewDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionViewDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionViewDropReason::Unknown) == 2);
    P2PublicSurfaceRetentionViewOutcome outcome{};
    assert(outcome.identity.view_id.value == 0);
    assert(outcome.status == P2PublicSurfaceRetentionViewStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_retention_view_outcome_default_construction" << std::endl;
}
