#include <cassert>
#include <iostream>
#include "playback/timeline_public_delta/classification/timeline_public_delta_kind.h"
#include "playback/timeline_public_delta/classification/timeline_public_delta_scope.h"
#include "playback/timeline_public_delta/classification/timeline_public_delta_classification.h"
namespace kivo::playback::timeline_public_delta {
void run_timeline_public_delta_classification_tests() {
    assert(static_cast<int>(TimelinePublicDeltaKind::Created) != static_cast<int>(TimelinePublicDeltaKind::Unknown));
    assert(static_cast<int>(TimelinePublicDeltaScope::Snapshot) != static_cast<int>(TimelinePublicDeltaScope::Unknown));
    TimelinePublicDeltaClassification c1;
    assert(c1.kind == TimelinePublicDeltaKind::Unknown);
    assert(c1.scope == TimelinePublicDeltaScope::Unknown);
    TimelinePublicDeltaClassification c2{TimelinePublicDeltaKind::Updated, TimelinePublicDeltaScope::UserVisible};
    assert(c2.kind == TimelinePublicDeltaKind::Updated);
    assert(c2.scope == TimelinePublicDeltaScope::UserVisible);
    std::cout << "  timeline_public_delta_classification_tests: ALL PASSED\n";
}
}
