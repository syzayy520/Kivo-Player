#include <cassert>
#include <iostream>
#include "playback/timeline_user_status_surface/surface/timeline_user_status_surface_candidate.h"
#include "playback/timeline_user_status_surface/surface/playback_timeline_user_status_surface.h"
#include "playback/timeline_user_status_surface/surface/timeline_user_status_surface_envelope.h"
#include "playback/timeline_user_status_surface/surface/timeline_user_status_surface_record.h"
namespace kivo::playback::timeline_user_status_surface {
void run_timeline_user_status_surface_tests() {
    TimelineUserStatusSurfaceCandidate cand1;
    assert(cand1.identity.surface_id.value == 0);
    assert(cand1.anchors.request_anchor.request_identity.request_id.value == 0);
    assert(cand1.classification.kind == TimelineUserStatusKind::Unknown);
    PlaybackTimelineUserStatusSurface surf1;
    assert(surf1.identity.surface_id.value == 0);
    TimelineUserStatusSurfaceEnvelope env1;
    assert(env1.identity.surface_id.value == 0);
    assert(env1.anchors.error_surface_anchor.error_surface_identity.surface_id.value == 0);
    TimelineUserStatusSurfaceRecord rec1;
    assert(rec1.envelope.identity.surface_id.value == 0);
    assert(rec1.surface.identity.surface_id.value == 0);
    TimelineUserStatusSurfaceRecord rec2{env1, surf1};
    assert(rec2.envelope.identity.surface_id.value == 0);
    std::cout << "  timeline_user_status_surface_tests: ALL PASSED\n";
}
}
