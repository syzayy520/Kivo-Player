#include <cassert>
#include <iostream>
#include "playback/timeline_error_surface/surface/timeline_error_surface_candidate.h"
#include "playback/timeline_error_surface/surface/playback_timeline_error_surface.h"
#include "playback/timeline_error_surface/surface/timeline_error_surface_envelope.h"
#include "playback/timeline_error_surface/surface/timeline_error_surface_record.h"
namespace kivo::playback::timeline_error_surface {
void run_timeline_error_surface_tests() {
    TimelineErrorSurfaceCandidate cand1;
    assert(cand1.identity.surface_id.value == 0);
    assert(cand1.anchors.request_anchor.request_identity.request_id.value == 0);
    assert(cand1.classification.category == TimelineErrorCategory::Unknown);
    PlaybackTimelineErrorSurface surf1;
    assert(surf1.identity.surface_id.value == 0);
    TimelineErrorSurfaceEnvelope env1;
    assert(env1.identity.surface_id.value == 0);
    assert(env1.anchors.result_anchor.result_report_identity.report_id.value == 0);
    TimelineErrorSurfaceRecord rec1;
    assert(rec1.envelope.identity.surface_id.value == 0);
    assert(rec1.surface.identity.surface_id.value == 0);
    TimelineErrorSurfaceRecord rec2{env1, surf1};
    assert(rec2.envelope.identity.surface_id.value == 0);
    std::cout << "  timeline_error_surface_tests: ALL PASSED\n";
}
}
