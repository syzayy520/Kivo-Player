#include <cassert>
#include <iostream>
#include "playback/timeline_public_delta/identity/timeline_public_delta_identity.h"
#include "playback/timeline_public_delta/anchor/timeline_public_delta_anchor_set.h"
#include "playback/timeline_public_delta/classification/timeline_public_delta_classification.h"
#include "playback/timeline_public_delta/delta/timeline_public_delta_record.h"
#include "playback/timeline_public_delta/outcome/timeline_public_delta_outcome.h"
namespace kivo::playback::timeline_public_delta {
void run_timeline_public_delta_boundary_tests() {
    TimelinePublicDeltaIdentity ident{.delta_id{1}, .sequence_id{2}, .generation{3}};
    assert(ident.delta_id.value == 1); assert(ident.sequence_id.value == 2); assert(ident.generation.value == 3);
    TimelinePublicDeltaClassification cls{TimelinePublicDeltaKind::Removed, TimelinePublicDeltaScope::DiagnosticSafe};
    assert(cls.kind == TimelinePublicDeltaKind::Removed);
    TimelinePublicDeltaRecord rec;
    rec.envelope.identity = ident;
    assert(rec.envelope.identity.delta_id.value == 1);
    TimelinePublicDeltaOutcome out{ident, TimelinePublicDeltaStatus::Rejected};
    assert(out.identity.delta_id.value == 1);
    assert(out.status == TimelinePublicDeltaStatus::Rejected);
    std::cout << "  timeline_public_delta_boundary_tests: ALL PASSED\n";
}
}
