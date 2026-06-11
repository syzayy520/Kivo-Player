#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_custody_view/outcome/p2_public_surface_custody_view_outcome.h"
#include "playback/p2_public_surface_custody_view/outcome/p2_public_surface_custody_view_rejection_reason.h"
#include "playback/p2_public_surface_custody_view/outcome/p2_public_surface_custody_view_defer_reason.h"

using namespace kivo::playback::p2_public_surface_custody_view;

void test_p2_public_surface_custody_view_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCustodyViewStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCustodyViewStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCustodyViewStatus::Deferred) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCustodyViewStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCustodyViewRejectionReason::RetentionAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCustodyViewRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCustodyViewRejectionReason::ViewIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCustodyViewRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCustodyViewDeferReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCustodyViewDeferReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCustodyViewDeferReason::Unknown) == 2);
    P2PublicSurfaceCustodyViewOutcome outcome{};
    assert(outcome.identity.view_id.value == 0);
    assert(outcome.status == P2PublicSurfaceCustodyViewStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_custody_view_outcome_default_construction" << std::endl;
}
