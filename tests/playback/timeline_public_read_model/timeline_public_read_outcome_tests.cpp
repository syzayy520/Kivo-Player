#include <cassert>
#include <iostream>
#include "playback/timeline_public_read_model/outcome/timeline_public_read_model_status.h"
#include "playback/timeline_public_read_model/outcome/timeline_public_read_model_rejection_reason.h"
#include "playback/timeline_public_read_model/outcome/timeline_public_read_model_drop_reason.h"
#include "playback/timeline_public_read_model/outcome/timeline_public_read_model_outcome.h"
namespace kivo::playback::timeline_public_read_model {
void run_timeline_public_read_outcome_tests() {
    assert(static_cast<int>(TimelinePublicReadModelStatus::Recorded) != static_cast<int>(TimelinePublicReadModelStatus::Unknown));
    assert(static_cast<int>(TimelinePublicReadModelRejectionReason::AnchorMissing) != static_cast<int>(TimelinePublicReadModelRejectionReason::Unknown));
    assert(static_cast<int>(TimelinePublicReadModelDropReason::Superseded) != static_cast<int>(TimelinePublicReadModelDropReason::Unknown));
    TimelinePublicReadModelOutcome out1;
    assert(out1.identity.read_model_id.value == 0);
    assert(out1.status == TimelinePublicReadModelStatus::Unknown);
    TimelinePublicReadModelOutcome out2{{.read_model_id{10}, .sequence_id{0}, .generation{0}}, TimelinePublicReadModelStatus::Recorded};
    assert(out2.identity.read_model_id.value == 10);
    assert(out2.status == TimelinePublicReadModelStatus::Recorded);
    std::cout << "  timeline_public_read_outcome_tests: ALL PASSED\n";
}
}
