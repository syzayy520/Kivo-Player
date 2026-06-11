#include <cassert>
#include <iostream>
#include "playback/timeline_public_read_model/model/timeline_public_read_model_candidate.h"
#include "playback/timeline_public_read_model/model/playback_timeline_public_read_model.h"
#include "playback/timeline_public_read_model/model/timeline_public_read_model_envelope.h"
#include "playback/timeline_public_read_model/model/timeline_public_read_model_record.h"
namespace kivo::playback::timeline_public_read_model {
void run_timeline_public_read_model_tests() {
    TimelinePublicReadModelCandidate cand1;
    assert(cand1.identity.read_model_id.value == 0);
    assert(cand1.anchors.request_anchor.request_identity.request_id.value == 0);
    assert(cand1.classification.scope == TimelinePublicReadModelScope::Unknown);
    PlaybackTimelinePublicReadModel surf1;
    assert(surf1.identity.read_model_id.value == 0);
    TimelinePublicReadModelEnvelope env1;
    assert(env1.identity.read_model_id.value == 0);
    assert(env1.anchors.user_status_surface_anchor.user_status_surface_identity.surface_id.value == 0);
    TimelinePublicReadModelRecord rec1;
    assert(rec1.envelope.identity.read_model_id.value == 0);
    assert(rec1.model.identity.read_model_id.value == 0);
    TimelinePublicReadModelRecord rec2{env1, surf1};
    assert(rec2.envelope.identity.read_model_id.value == 0);
    std::cout << "  timeline_public_read_model_tests: ALL PASSED\n";
}
}
