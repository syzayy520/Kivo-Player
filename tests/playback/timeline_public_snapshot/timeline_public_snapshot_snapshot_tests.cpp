#include <cassert>
#include <iostream>
#include "playback/timeline_public_snapshot/snapshot/timeline_public_snapshot_candidate.h"
#include "playback/timeline_public_snapshot/snapshot/playback_timeline_public_snapshot.h"
#include "playback/timeline_public_snapshot/snapshot/timeline_public_snapshot_envelope.h"
#include "playback/timeline_public_snapshot/snapshot/timeline_public_snapshot_record.h"
namespace kivo::playback::timeline_public_snapshot {
void run_timeline_public_snapshot_snapshot_tests() {
    TimelinePublicSnapshotCandidate cand1;
    assert(cand1.identity.snapshot_id.value == 0);
    assert(cand1.anchors.read_model_anchor.read_model_identity.read_model_id.value == 0);
    PlaybackTimelinePublicSnapshot snap1;
    assert(snap1.identity.snapshot_id.value == 0);
    TimelinePublicSnapshotEnvelope env1;
    assert(env1.identity.snapshot_id.value == 0);
    TimelinePublicSnapshotRecord rec1;
    assert(rec1.envelope.identity.snapshot_id.value == 0);
    assert(rec1.snapshot.identity.snapshot_id.value == 0);
    TimelinePublicSnapshotRecord rec2{env1, snap1};
    assert(rec2.envelope.identity.snapshot_id.value == 0);
    std::cout << "  timeline_public_snapshot_snapshot_tests: ALL PASSED\n";
}
}
