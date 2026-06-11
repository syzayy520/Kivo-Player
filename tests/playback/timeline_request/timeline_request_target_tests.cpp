#include <cassert>
#include <iostream>
#include "playback/timeline_request/target/timeline_target_kind.h"
#include "playback/timeline_request/target/timeline_position_target.h"
#include "playback/timeline_request/target/timeline_control_target_ref.h"
#include "playback/timeline_request/target/timeline_request_target.h"
namespace kivo::playback::timeline_request {
void run_timeline_request_target_tests() {
    assert(static_cast<int>(TimelineTargetKind::Position) != static_cast<int>(TimelineTargetKind::ControlTarget));
    assert(static_cast<int>(TimelineTargetKind::Unknown) != static_cast<int>(TimelineTargetKind::Position));
    TimelinePositionTarget pt1; assert(pt1.position.value == 0);
    kivo::playback::timeline::MediaTimestamp pos; pos.value = 100;
    TimelinePositionTarget pt2{pos}; assert(pt2.position.value == 100);
    TimelineControlTargetRef ct1; assert(ct1.target.kind == kivo::playback::control::PlaybackControlTargetKind::Unknown);
    TimelineRequestTarget tgt1;
    assert(tgt1.kind == TimelineTargetKind::Unknown);
    TimelineRequestTarget tgt2{TimelineTargetKind::Position, pt2, {}};
    assert(tgt2.kind == TimelineTargetKind::Position);
    assert(tgt2.position_target.position.value == 100);
    std::cout << "  timeline_request_target_tests: ALL PASSED\n";
}
}
