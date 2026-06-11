#include <cassert>
#include <iostream>
#include "playback/timeline_state_summary/summary/timeline_state_summary_candidate.h"
#include "playback/timeline_state_summary/summary/playback_timeline_state_summary.h"
#include "playback/timeline_state_summary/summary/timeline_state_summary_envelope.h"
#include "playback/timeline_state_summary/summary/timeline_state_summary_record.h"
namespace kivo::playback::timeline_state_summary {
void run_timeline_state_summary_tests() {
    TimelineStateSummaryIdentity ident{.summary_id{1}, .sequence_id{2}, .generation{3}};
    TimelineStateSummaryCandidate c1; assert(c1.identity.summary_id.value == 0);
    TimelineStateSummaryCandidate c2{ident}; assert(c2.identity.summary_id.value == 1);
    PlaybackTimelineStateSummary s1; assert(s1.identity.summary_id.value == 0);
    PlaybackTimelineStateSummary s2{ident}; assert(s2.identity.summary_id.value == 1);
    TimelineStateSummaryEnvelope env1; assert(env1.identity.summary_id.value == 0);
    TimelineStateSummaryEnvelope env2{ident}; assert(env2.identity.summary_id.value == 1);
    TimelineStateSummaryRecord rec1; assert(rec1.envelope.identity.summary_id.value == 0);
    assert(rec1.summary.identity.summary_id.value == 0);
    TimelineStateSummaryRecord rec2{env2, s2}; assert(rec2.envelope.identity.summary_id.value == 1);
    assert(rec2.summary.identity.summary_id.value == 1);
    std::cout << "  timeline_state_summary_tests: ALL PASSED\n";
}
}
