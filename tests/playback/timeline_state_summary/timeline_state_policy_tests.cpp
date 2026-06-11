#include <cassert>
#include <iostream>
#include "playback/timeline_state_summary/policy/timeline_state_summary_kind.h"
#include "playback/timeline_state_summary/policy/timeline_state_completeness_policy.h"
#include "playback/timeline_state_summary/policy/timeline_state_priority.h"
#include "playback/timeline_state_summary/policy/timeline_state_summary_policy.h"
namespace kivo::playback::timeline_state_summary {
void run_timeline_state_policy_tests() {
    assert(static_cast<int>(TimelineStateSummaryKind::IdentityOnly) != static_cast<int>(TimelineStateSummaryKind::LinkedChain));
    assert(static_cast<int>(TimelineStateCompletenessPolicy::AllowPartial) != static_cast<int>(TimelineStateCompletenessPolicy::RequireSnapshot));
    assert(static_cast<int>(TimelineStatePriority::Low) != static_cast<int>(TimelineStatePriority::High));
    TimelineStateSummaryPolicy p1;
    assert(p1.summary_kind == TimelineStateSummaryKind::Unknown);
    assert(p1.completeness_policy == TimelineStateCompletenessPolicy::Unknown);
    assert(p1.priority == TimelineStatePriority::Unknown);
    TimelineStateSummaryPolicy p2{TimelineStateSummaryKind::LinkedChain, TimelineStateCompletenessPolicy::RequireResult, TimelineStatePriority::High};
    assert(p2.summary_kind == TimelineStateSummaryKind::LinkedChain);
    assert(p2.completeness_policy == TimelineStateCompletenessPolicy::RequireResult);
    assert(p2.priority == TimelineStatePriority::High);
    std::cout << "  timeline_state_policy_tests: ALL PASSED\n";
}
}
