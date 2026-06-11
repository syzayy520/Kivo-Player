#include <cassert>
#include <iostream>
#include "playback/timeline_public_read_model/classification/timeline_public_read_model_scope.h"
#include "playback/timeline_public_read_model/classification/timeline_public_read_model_freshness.h"
#include "playback/timeline_public_read_model/classification/timeline_public_read_model_attention.h"
#include "playback/timeline_public_read_model/classification/timeline_public_read_model_classification.h"
namespace kivo::playback::timeline_public_read_model {
void run_timeline_public_read_classification_tests() {
    assert(static_cast<int>(TimelinePublicReadModelScope::Timeline) != static_cast<int>(TimelinePublicReadModelScope::Unknown));
    assert(static_cast<int>(TimelinePublicReadModelFreshness::Fresh) != static_cast<int>(TimelinePublicReadModelFreshness::Unknown));
    assert(static_cast<int>(TimelinePublicReadModelAttention::Blocking) != static_cast<int>(TimelinePublicReadModelAttention::Unknown));
    TimelinePublicReadModelClassification c1;
    assert(c1.scope == TimelinePublicReadModelScope::Unknown);
    assert(c1.freshness == TimelinePublicReadModelFreshness::Unknown);
    assert(c1.attention == TimelinePublicReadModelAttention::Unknown);
    TimelinePublicReadModelClassification c2{TimelinePublicReadModelScope::Playback, TimelinePublicReadModelFreshness::Fresh, TimelinePublicReadModelAttention::None};
    assert(c2.scope == TimelinePublicReadModelScope::Playback);
    assert(c2.freshness == TimelinePublicReadModelFreshness::Fresh);
    std::cout << "  timeline_public_read_classification_tests: ALL PASSED\n";
}
}
