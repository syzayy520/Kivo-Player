#include <cassert>
#include <iostream>
#include "playback/timeline_user_status_surface/identity/timeline_user_status_surface_identity.h"
#include "playback/timeline_user_status_surface/anchor/timeline_user_status_anchor_set.h"
#include "playback/timeline_user_status_surface/classification/timeline_user_status_classification.h"
#include "playback/timeline_user_status_surface/surface/timeline_user_status_surface_record.h"
#include "playback/timeline_user_status_surface/outcome/timeline_user_status_surface_outcome.h"
namespace kivo::playback::timeline_user_status_surface {
void run_timeline_user_status_boundary_tests() {
    TimelineUserStatusSurfaceIdentity ident{.surface_id{1}, .sequence_id{2}, .generation{3}};
    assert(ident.surface_id.value == 1); assert(ident.sequence_id.value == 2); assert(ident.generation.value == 3);
    TimelineUserStatusClassification cls{TimelineUserStatusKind::Error, TimelineUserStatusReadiness::Blocked, TimelineUserStatusAttention::Blocking};
    assert(cls.kind == TimelineUserStatusKind::Error); assert(cls.readiness == TimelineUserStatusReadiness::Blocked);
    TimelineUserStatusSurfaceRecord rec;
    rec.envelope.identity = ident;
    assert(rec.envelope.identity.surface_id.value == 1);
    TimelineUserStatusSurfaceOutcome out{ident, TimelineUserStatusSurfaceStatus::Rejected};
    assert(out.identity.surface_id.value == 1);
    assert(out.status == TimelineUserStatusSurfaceStatus::Rejected);
    std::cout << "  timeline_user_status_boundary_tests: ALL PASSED\n";
}
}
