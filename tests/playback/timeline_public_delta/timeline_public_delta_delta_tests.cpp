#include <cassert>
#include <iostream>
#include "playback/timeline_public_delta/delta/timeline_public_delta_candidate.h"
#include "playback/timeline_public_delta/delta/playback_timeline_public_delta.h"
#include "playback/timeline_public_delta/delta/timeline_public_delta_envelope.h"
#include "playback/timeline_public_delta/delta/timeline_public_delta_record.h"
namespace kivo::playback::timeline_public_delta {
void run_timeline_public_delta_delta_tests() {
    TimelinePublicDeltaCandidate cand1;
    assert(cand1.identity.delta_id.value == 0);
    assert(cand1.anchors.snapshot_anchor.snapshot_identity.snapshot_id.value == 0);
    PlaybackTimelinePublicDelta delta1;
    assert(delta1.identity.delta_id.value == 0);
    TimelinePublicDeltaEnvelope env1;
    assert(env1.identity.delta_id.value == 0);
    TimelinePublicDeltaRecord rec1;
    assert(rec1.envelope.identity.delta_id.value == 0);
    assert(rec1.delta.identity.delta_id.value == 0);
    TimelinePublicDeltaRecord rec2{env1, delta1};
    assert(rec2.envelope.identity.delta_id.value == 0);
    std::cout << "  timeline_public_delta_delta_tests: ALL PASSED\n";
}
}
