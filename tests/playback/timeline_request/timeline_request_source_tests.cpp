#include <cassert>
#include <iostream>
#include "playback/timeline_request/source/timeline_request_source_kind.h"
#include "playback/timeline_request/source/timeline_control_source_ref.h"
#include "playback/timeline_request/source/timeline_session_source_ref.h"
#include "playback/timeline_request/source/timeline_request_source.h"
namespace kivo::playback::timeline_request {
void run_timeline_request_source_tests() {
    assert(static_cast<int>(TimelineRequestSourceKind::Control) != static_cast<int>(TimelineRequestSourceKind::Session));
    assert(static_cast<int>(TimelineRequestSourceKind::Unknown) != static_cast<int>(TimelineRequestSourceKind::Control));
    TimelineControlSourceRef cr; assert(cr.request_id.value == 0);
    kivo::playback::control::ControlRequestId cid{99};
    TimelineControlSourceRef cr2{cid}; assert(cr2.request_id.value == 99);
    TimelineSessionSourceRef sr; assert(sr.session_id.value == 0);
    kivo::playback::orchestration::PlaybackSessionId sid{55};
    TimelineSessionSourceRef sr2{sid}; assert(sr2.session_id.value == 55);
    TimelineRequestSource src1;
    assert(src1.kind == TimelineRequestSourceKind::Unknown);
    TimelineRequestSource src2{TimelineRequestSourceKind::Control, cr2, {}};
    assert(src2.kind == TimelineRequestSourceKind::Control);
    assert(src2.control_source.request_id.value == 99);
    TimelineRequestSource src3{TimelineRequestSourceKind::Session, {}, sr2};
    assert(src3.kind == TimelineRequestSourceKind::Session);
    assert(src3.session_source.session_id.value == 55);
    std::cout << "  timeline_request_source_tests: ALL PASSED\n";
}
}
