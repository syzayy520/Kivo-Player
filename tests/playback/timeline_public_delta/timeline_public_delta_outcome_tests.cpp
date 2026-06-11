#include <cassert>
#include <iostream>
#include "playback/timeline_public_delta/outcome/timeline_public_delta_status.h"
#include "playback/timeline_public_delta/outcome/timeline_public_delta_rejection_reason.h"
#include "playback/timeline_public_delta/outcome/timeline_public_delta_drop_reason.h"
#include "playback/timeline_public_delta/outcome/timeline_public_delta_outcome.h"
namespace kivo::playback::timeline_public_delta {
void run_timeline_public_delta_outcome_tests() {
    assert(static_cast<int>(TimelinePublicDeltaStatus::Recorded) != static_cast<int>(TimelinePublicDeltaStatus::Unknown));
    assert(static_cast<int>(TimelinePublicDeltaRejectionReason::SnapshotAnchorMissing) != static_cast<int>(TimelinePublicDeltaRejectionReason::Unknown));
    assert(static_cast<int>(TimelinePublicDeltaDropReason::Superseded) != static_cast<int>(TimelinePublicDeltaDropReason::Unknown));
    TimelinePublicDeltaOutcome out1;
    assert(out1.identity.delta_id.value == 0);
    assert(out1.status == TimelinePublicDeltaStatus::Unknown);
    TimelinePublicDeltaOutcome out2{{.delta_id{10}, .sequence_id{0}, .generation{0}}, TimelinePublicDeltaStatus::Recorded};
    assert(out2.identity.delta_id.value == 10);
    assert(out2.status == TimelinePublicDeltaStatus::Recorded);
    std::cout << "  timeline_public_delta_outcome_tests: ALL PASSED\n";
}
}
