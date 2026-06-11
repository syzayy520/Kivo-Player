#include <cassert>
#include <iostream>
#include "playback/timeline_request/normalization/timeline_normalization_policy.h"
#include "playback/timeline_request/normalization/normalized_timeline_request.h"
#include "playback/timeline_request/normalization/timeline_normalization_record.h"
#include "playback/timeline_request/normalization/timeline_request_envelope.h"
namespace kivo::playback::timeline_request {
void run_timeline_request_normalization_tests() {
    assert(static_cast<int>(TimelineNormalizationPolicy::Strict) != static_cast<int>(TimelineNormalizationPolicy::PreserveTarget));
    assert(static_cast<int>(TimelineNormalizationPolicy::Unknown) != static_cast<int>(TimelineNormalizationPolicy::PreserveDeadline));
    NormalizedTimelineRequest nr1;
    assert(nr1.identity.request_id.value == 0);
    assert(nr1.request.session_id.value == 0);
    TimelineRequestIdentity ident{.request_id{1}, .sequence_id{2}, .generation{3}};
    kivo::playback::orchestration::PlaybackSessionId sid{10};
    kivo::playback::timeline::MediaTimestamp pos; pos.value = 200;
    kivo::playback::presentation::PresentationDeadline dl{3000, 200};
    kivo::playback::orchestration::PlaybackTimelineRequest req{sid, pos, dl};
    NormalizedTimelineRequest nr2{ident, req};
    assert(nr2.identity.request_id.value == 1);
    assert(nr2.request.session_id.value == 10);
    assert(nr2.request.target_position.value == 200);
    assert(nr2.request.deadline.deadline_us == 3000);
    TimelineRequestEnvelope env1;
    assert(env1.identity.request_id.value == 0);
    TimelineRequestEnvelope env2{ident};
    assert(env2.identity.request_id.value == 1);
    assert(env2.identity.sequence_id.value == 2);
    TimelineNormalizationRecord rec1;
    assert(rec1.identity.request_id.value == 0);
    assert(rec1.normalization_policy == TimelineNormalizationPolicy::Unknown);
    TimelineNormalizationRecord rec2{ident, {}, {}, {}, TimelineNormalizationPolicy::Strict, nr2};
    assert(rec2.identity.request_id.value == 1);
    assert(rec2.normalization_policy == TimelineNormalizationPolicy::Strict);
    assert(rec2.normalized_request.request.session_id.value == 10);
    std::cout << "  timeline_request_normalization_tests: ALL PASSED\n";
}
}
