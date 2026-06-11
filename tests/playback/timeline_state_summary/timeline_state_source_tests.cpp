#include <cassert>
#include <iostream>
#include "playback/timeline_state_summary/source/timeline_state_source_kind.h"
#include "playback/timeline_state_summary/source/timeline_request_identity_source_ref.h"
#include "playback/timeline_state_summary/source/timeline_snapshot_observation_source_ref.h"
#include "playback/timeline_state_summary/source/timeline_state_source.h"
namespace kivo::playback::timeline_state_summary {
void run_timeline_state_source_tests() {
    assert(static_cast<int>(TimelineStateSourceKind::RequestIdentity) != static_cast<int>(TimelineStateSourceKind::SnapshotObservationIdentity));
    assert(static_cast<int>(TimelineStateSourceKind::Unknown) != static_cast<int>(TimelineStateSourceKind::Synthetic));
    TimelineRequestIdentitySourceRef ri1; assert(ri1.request_identity.request_id.value == 0);
    kivo::playback::timeline_request::TimelineRequestIdentity ident{.request_id{5}, .sequence_id{6}, .generation{7}};
    TimelineRequestIdentitySourceRef ri2{ident}; assert(ri2.request_identity.request_id.value == 5);
    TimelineSnapshotObservationSourceRef so1; assert(so1.snapshot_observation_identity.observation_id.value == 0);
    kivo::playback::timeline_snapshot_observation::TimelineSnapshotObservationIdentity oid{.observation_id{10}, .sequence_id{20}, .generation{30}};
    TimelineSnapshotObservationSourceRef so2{oid}; assert(so2.snapshot_observation_identity.observation_id.value == 10);
    TimelineStateSource src1; assert(src1.kind == TimelineStateSourceKind::Unknown);
    TimelineStateSource src2{TimelineStateSourceKind::RequestIdentity, ri2, {}}; assert(src2.request_source.request_identity.request_id.value == 5);
    std::cout << "  timeline_state_source_tests: ALL PASSED\n";
}
}
