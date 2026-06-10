#include <cassert>
#include <iostream>
#include "playback/orchestration/timeline/playback_timeline_snapshot.h"
#include "playback/orchestration/timeline/playback_timeline_request.h"
#include "playback/orchestration/timeline/playback_timeline_decision.h"
#include "playback/orchestration/timeline/playback_timeline_result.h"

namespace kivo::playback::orchestration {
void run_playback_timeline_tests() {
    PlaybackTimelineSnapshot snap1;
    assert(snap1.session_id.value == 0);
    assert(snap1.position.value == 0);
    PlaybackTimelineSnapshot snap2{
        .session_id{PlaybackSessionId{100}},
        .position{kivo::playback::timeline::MediaTimestamp{{}, 50000}}
    };
    assert(snap2.position.value == 50000);

    PlaybackTimelineRequest req1;
    assert(req1.session_id.value == 0);
    assert(req1.target_position.value == 0);
    assert(req1.deadline.deadline_us == 0);
    PlaybackTimelineRequest req2{
        .session_id{PlaybackSessionId{200}},
        .target_position{kivo::playback::timeline::MediaTimestamp{{}, 100000}},
        .deadline{kivo::playback::presentation::PresentationDeadline{33333, 1000}}
    };
    assert(req2.target_position.value == 100000);
    assert(req2.deadline.deadline_us == 33333);

    PlaybackTimelineDecision dec1;
    assert(dec1.session_id.value == 0);
    assert(dec1.decision == kivo::playback::presentation::PresentationDecision::Unknown);
    PlaybackTimelineDecision dec2{
        .session_id{PlaybackSessionId{300}},
        .decision{kivo::playback::presentation::PresentationDecision::Present}
    };
    assert(dec2.decision == kivo::playback::presentation::PresentationDecision::Present);

    PlaybackTimelineResult result1;
    assert(result1.session_id.value == 0);
    assert(result1.decision.decision == kivo::playback::presentation::PresentationDecision::Unknown);
    PlaybackTimelineResult result2{
        .session_id{PlaybackSessionId{400}},
        .decision{.session_id{PlaybackSessionId{400}}, .decision{kivo::playback::presentation::PresentationDecision::Drop}}
    };
    assert(result2.decision.decision == kivo::playback::presentation::PresentationDecision::Drop);

    std::cout << "  playback_timeline_tests: ALL PASSED\n";
}
}
