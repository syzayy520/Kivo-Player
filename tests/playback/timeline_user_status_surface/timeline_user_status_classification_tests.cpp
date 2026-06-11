#include <cassert>
#include <iostream>
#include "playback/timeline_user_status_surface/classification/timeline_user_status_kind.h"
#include "playback/timeline_user_status_surface/classification/timeline_user_status_readiness.h"
#include "playback/timeline_user_status_surface/classification/timeline_user_status_attention.h"
#include "playback/timeline_user_status_surface/classification/timeline_user_status_classification.h"
namespace kivo::playback::timeline_user_status_surface {
void run_timeline_user_status_classification_tests() {
    assert(static_cast<int>(TimelineUserStatusKind::Playing) != static_cast<int>(TimelineUserStatusKind::Unknown));
    assert(static_cast<int>(TimelineUserStatusReadiness::Ready) != static_cast<int>(TimelineUserStatusReadiness::Unknown));
    assert(static_cast<int>(TimelineUserStatusAttention::Blocking) != static_cast<int>(TimelineUserStatusAttention::Unknown));
    TimelineUserStatusClassification c1;
    assert(c1.kind == TimelineUserStatusKind::Unknown);
    assert(c1.readiness == TimelineUserStatusReadiness::Unknown);
    assert(c1.attention == TimelineUserStatusAttention::Unknown);
    TimelineUserStatusClassification c2{TimelineUserStatusKind::Playing, TimelineUserStatusReadiness::Ready, TimelineUserStatusAttention::None};
    assert(c2.kind == TimelineUserStatusKind::Playing);
    assert(c2.readiness == TimelineUserStatusReadiness::Ready);
    std::cout << "  timeline_user_status_classification_tests: ALL PASSED\n";
}
}
