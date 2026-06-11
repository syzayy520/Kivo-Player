#include <cassert>
#include <iostream>
#include "playback/timeline_public_read_model/identity/timeline_public_read_model_identity.h"
#include "playback/timeline_public_read_model/anchor/timeline_public_read_anchor_set.h"
#include "playback/timeline_public_read_model/classification/timeline_public_read_model_classification.h"
#include "playback/timeline_public_read_model/model/timeline_public_read_model_record.h"
#include "playback/timeline_public_read_model/outcome/timeline_public_read_model_outcome.h"
namespace kivo::playback::timeline_public_read_model {
void run_timeline_public_read_boundary_tests() {
    TimelinePublicReadModelIdentity ident{.read_model_id{1}, .sequence_id{2}, .generation{3}};
    assert(ident.read_model_id.value == 1); assert(ident.sequence_id.value == 2); assert(ident.generation.value == 3);
    TimelinePublicReadModelClassification cls{TimelinePublicReadModelScope::UserVisible, TimelinePublicReadModelFreshness::Stale, TimelinePublicReadModelAttention::Warning};
    assert(cls.scope == TimelinePublicReadModelScope::UserVisible); assert(cls.freshness == TimelinePublicReadModelFreshness::Stale);
    TimelinePublicReadModelRecord rec;
    rec.envelope.identity = ident;
    assert(rec.envelope.identity.read_model_id.value == 1);
    TimelinePublicReadModelOutcome out{ident, TimelinePublicReadModelStatus::Rejected};
    assert(out.identity.read_model_id.value == 1);
    assert(out.status == TimelinePublicReadModelStatus::Rejected);
    std::cout << "  timeline_public_read_boundary_tests: ALL PASSED\n";
}
}
