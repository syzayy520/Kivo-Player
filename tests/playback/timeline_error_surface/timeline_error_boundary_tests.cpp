#include <cassert>
#include <iostream>
#include "playback/timeline_error_surface/identity/timeline_error_surface_identity.h"
#include "playback/timeline_error_surface/anchor/timeline_error_anchor_set.h"
#include "playback/timeline_error_surface/classification/timeline_error_classification.h"
#include "playback/timeline_error_surface/surface/timeline_error_surface_record.h"
#include "playback/timeline_error_surface/outcome/timeline_error_surface_outcome.h"
namespace kivo::playback::timeline_error_surface {
void run_timeline_error_boundary_tests() {
    TimelineErrorSurfaceIdentity ident{.surface_id{1}, .sequence_id{2}, .generation{3}};
    assert(ident.surface_id.value == 1);
    assert(ident.sequence_id.value == 2);
    assert(ident.generation.value == 3);
    TimelineErrorClassification cls{TimelineErrorCategory::ChainIntegrity, TimelineErrorSeverity::Fatal, TimelineErrorRecoverability::NotRecoverable, TimelineErrorPhase::DuringChainIntegrity};
    assert(cls.category == TimelineErrorCategory::ChainIntegrity);
    assert(cls.severity == TimelineErrorSeverity::Fatal);
    TimelineErrorSurfaceRecord rec;
    rec.envelope.identity = ident;
    assert(rec.envelope.identity.surface_id.value == 1);
    TimelineErrorSurfaceOutcome out{ident, TimelineErrorSurfaceStatus::Rejected};
    assert(out.identity.surface_id.value == 1);
    assert(out.status == TimelineErrorSurfaceStatus::Rejected);
    std::cout << "  timeline_error_boundary_tests: ALL PASSED\n";
}
}
