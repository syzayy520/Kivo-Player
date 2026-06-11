#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_persistence_view/outcome/p2_public_surface_persistence_view_outcome.h"
#include "playback/p2_public_surface_persistence_view/outcome/p2_public_surface_persistence_view_rejection_reason.h"
#include "playback/p2_public_surface_persistence_view/outcome/p2_public_surface_persistence_view_drop_reason.h"

using namespace kivo::playback::p2_public_surface_persistence_view;

void test_p2_public_surface_persistence_view_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfacePersistenceViewStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePersistenceViewStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePersistenceViewStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePersistenceViewStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePersistenceViewRejectionReason::DurabilityAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePersistenceViewRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePersistenceViewRejectionReason::ViewIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePersistenceViewRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePersistenceViewDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePersistenceViewDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePersistenceViewDropReason::Unknown) == 2);
    P2PublicSurfacePersistenceViewOutcome outcome{};
    assert(outcome.identity.view_id.value == 0);
    assert(outcome.status == P2PublicSurfacePersistenceViewStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_persistence_view_outcome_default_construction" << std::endl;
}
