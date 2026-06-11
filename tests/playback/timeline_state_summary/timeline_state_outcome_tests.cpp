#include <cassert>
#include <iostream>
#include "playback/timeline_state_summary/outcome/timeline_state_summary_status.h"
#include "playback/timeline_state_summary/outcome/timeline_state_summary_outcome.h"
#include "playback/timeline_state_summary/outcome/timeline_state_rejection_reason.h"
#include "playback/timeline_state_summary/outcome/timeline_state_drop_reason.h"
namespace kivo::playback::timeline_state_summary {
void run_timeline_state_outcome_tests() {
    assert(static_cast<int>(TimelineStateSummaryStatus::Summarized) != static_cast<int>(TimelineStateSummaryStatus::Rejected));
    assert(static_cast<int>(TimelineStateSummaryStatus::Partial) != static_cast<int>(TimelineStateSummaryStatus::Dropped));
    assert(static_cast<int>(TimelineStateRejectionReason::InputInvalid) != static_cast<int>(TimelineStateRejectionReason::ChainIdentityMissing));
    assert(static_cast<int>(TimelineStateDropReason::Superseded) != static_cast<int>(TimelineStateDropReason::PriorityOverridden));
    TimelineStateSummaryOutcome o1; assert(o1.status == TimelineStateSummaryStatus::Unknown);
    TimelineStateSummaryIdentity ident{.summary_id{10}, .sequence_id{20}, .generation{30}};
    TimelineStateSummaryOutcome o2{ident, TimelineStateSummaryStatus::Summarized};
    assert(o2.identity.summary_id.value == 10); assert(o2.status == TimelineStateSummaryStatus::Summarized);
    std::cout << "  timeline_state_outcome_tests: ALL PASSED\n";
}
}
