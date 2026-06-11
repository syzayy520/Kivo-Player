#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_coherence_view/outcome/p2_public_surface_coherence_view_outcome.h"
#include "playback/p2_public_surface_coherence_view/outcome/p2_public_surface_coherence_view_rejection_reason.h"
#include "playback/p2_public_surface_coherence_view/outcome/p2_public_surface_coherence_view_drop_reason.h"

using namespace kivo::playback::p2_public_surface_coherence_view;

void test_p2_public_surface_coherence_view_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCoherenceViewStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCoherenceViewStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCoherenceViewStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCoherenceViewStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCoherenceViewRejectionReason::IntegrityAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCoherenceViewRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCoherenceViewRejectionReason::ViewIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCoherenceViewRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCoherenceViewDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCoherenceViewDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCoherenceViewDropReason::Unknown) == 2);
    P2PublicSurfaceCoherenceViewOutcome outcome{};
    assert(outcome.identity.view_id.value == 0);
    assert(outcome.status == P2PublicSurfaceCoherenceViewStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_coherence_view_outcome_default_construction" << std::endl;
}
