#include <cassert>
#include <iostream>
#include "playback/timeline_public_snapshot/anchor/timeline_public_read_model_snapshot_anchor.h"
#include "playback/timeline_public_snapshot/anchor/timeline_public_snapshot_anchor_set.h"
namespace kivo::playback::timeline_public_snapshot {
void run_timeline_public_snapshot_anchor_tests() {
    TimelinePublicReadModelSnapshotAnchor a1;
    assert(a1.read_model_identity.read_model_id.value == 0);
    TimelinePublicSnapshotAnchorSet set1;
    assert(set1.read_model_anchor.read_model_identity.read_model_id.value == 0);
    std::cout << "  timeline_public_snapshot_anchor_tests: ALL PASSED\n";
}
}
