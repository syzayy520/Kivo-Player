#include <cassert>
#include <iostream>
#include "playback/timeline_public_delta/anchor/timeline_public_snapshot_delta_anchor.h"
#include "playback/timeline_public_delta/anchor/timeline_public_delta_anchor_set.h"
namespace kivo::playback::timeline_public_delta {
void run_timeline_public_delta_anchor_tests() {
    TimelinePublicSnapshotDeltaAnchor a1;
    assert(a1.snapshot_identity.snapshot_id.value == 0);
    TimelinePublicDeltaAnchorSet set1;
    assert(set1.snapshot_anchor.snapshot_identity.snapshot_id.value == 0);
    std::cout << "  timeline_public_delta_anchor_tests: ALL PASSED\n";
}
}
