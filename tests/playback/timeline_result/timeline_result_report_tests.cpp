#include <cassert>
#include <iostream>
#include "playback/timeline_result/report/timeline_result_report_candidate.h"
#include "playback/timeline_result/report/reported_timeline_result.h"
#include "playback/timeline_result/report/timeline_result_report_envelope.h"
#include "playback/timeline_result/report/timeline_result_report_record.h"
namespace kivo::playback::timeline_result {
void run_timeline_result_report_tests() {
    TimelineResultReportIdentity ident{.report_id{1}, .sequence_id{2}, .generation{3}};
    TimelineResultReportCandidate c1;
    assert(c1.identity.report_id.value == 0);
    assert(c1.result.session_id.value == 0);
    kivo::playback::orchestration::PlaybackTimelineResult res;
    res.decision.decision = kivo::playback::presentation::PresentationDecision::Present;
    TimelineResultReportCandidate c2{ident, res};
    assert(c2.identity.report_id.value == 1);
    assert(c2.result.decision.decision == kivo::playback::presentation::PresentationDecision::Present);
    ReportedTimelineResult r1;
    assert(r1.identity.report_id.value == 0);
    ReportedTimelineResult r2{ident, res};
    assert(r2.result.decision.decision == kivo::playback::presentation::PresentationDecision::Present);
    TimelineResultReportEnvelope env1;
    assert(env1.identity.report_id.value == 0);
    TimelineResultReportEnvelope env2{ident};
    assert(env2.identity.report_id.value == 1);
    TimelineResultReportRecord rec1;
    assert(rec1.envelope.identity.report_id.value == 0);
    assert(rec1.reported_result.identity.report_id.value == 0);
    TimelineResultReportRecord rec2{env2, r2};
    assert(rec2.envelope.identity.report_id.value == 1);
    assert(rec2.reported_result.result.decision.decision == kivo::playback::presentation::PresentationDecision::Present);
    std::cout << "  timeline_result_report_tests: ALL PASSED\n";
}
}
