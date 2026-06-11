#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_snapshot/outcome/p2_public_surface_snapshot_outcome.h"
#include "playback/p2_public_surface_snapshot/outcome/p2_public_surface_snapshot_rejection_reason.h"
#include "playback/p2_public_surface_snapshot/outcome/p2_public_surface_snapshot_drop_reason.h"

using namespace kivo::playback::p2_public_surface_snapshot;

void test_p2_public_surface_snapshot_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceSnapshotStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceSnapshotStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceSnapshotStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceSnapshotStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceSnapshotRejectionReason::ObservationAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceSnapshotRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceSnapshotRejectionReason::SnapshotIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceSnapshotRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceSnapshotDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceSnapshotDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceSnapshotDropReason::Unknown) == 2);
    P2PublicSurfaceSnapshotOutcome outcome{};
    assert(outcome.identity.snapshot_id.value == 0);
    assert(outcome.status == P2PublicSurfaceSnapshotStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_snapshot_outcome_default_construction" << std::endl;
}
