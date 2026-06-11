#include <cassert>
#include <iostream>
#include "playback/timeline_request/policy/timeline_deadline_policy.h"
#include "playback/timeline_request/policy/timeline_clamp_policy.h"
#include "playback/timeline_request/policy/timeline_request_priority.h"
#include "playback/timeline_request/policy/timeline_request_policy.h"
namespace kivo::playback::timeline_request {
void run_timeline_request_policy_tests() {
    assert(static_cast<int>(TimelineDeadlinePolicy::None) != static_cast<int>(TimelineDeadlinePolicy::Required));
    assert(static_cast<int>(TimelineDeadlinePolicy::Unknown) != static_cast<int>(TimelineDeadlinePolicy::Preserve));
    assert(static_cast<int>(TimelineClampPolicy::None) != static_cast<int>(TimelineClampPolicy::RejectOutOfRange));
    assert(static_cast<int>(TimelineClampPolicy::Unknown) != static_cast<int>(TimelineClampPolicy::ClampToKnownRange));
    assert(static_cast<int>(TimelineRequestPriority::Low) != static_cast<int>(TimelineRequestPriority::High));
    assert(static_cast<int>(TimelineRequestPriority::Unknown) != static_cast<int>(TimelineRequestPriority::Normal));
    TimelineRequestPolicy p1;
    assert(p1.deadline_policy == TimelineDeadlinePolicy::Unknown);
    assert(p1.clamp_policy == TimelineClampPolicy::Unknown);
    assert(p1.priority == TimelineRequestPriority::Unknown);
    assert(p1.deadline.deadline_us == 0); assert(p1.deadline.tolerance_us == 0);
    kivo::playback::presentation::PresentationDeadline dl{1000, 100};
    TimelineRequestPolicy p2{TimelineDeadlinePolicy::Required, TimelineClampPolicy::ClampToKnownRange, TimelineRequestPriority::High, dl};
    assert(p2.deadline_policy == TimelineDeadlinePolicy::Required);
    assert(p2.clamp_policy == TimelineClampPolicy::ClampToKnownRange);
    assert(p2.priority == TimelineRequestPriority::High);
    assert(p2.deadline.deadline_us == 1000); assert(p2.deadline.tolerance_us == 100);
    std::cout << "  timeline_request_policy_tests: ALL PASSED\n";
}
}
