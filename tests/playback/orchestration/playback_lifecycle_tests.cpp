#include <cassert>
#include <iostream>
#include "playback/orchestration/lifecycle/playback_lifecycle_state.h"
#include "playback/orchestration/lifecycle/playback_lifecycle_request.h"
#include "playback/orchestration/lifecycle/playback_lifecycle_transition.h"
#include "playback/orchestration/lifecycle/playback_lifecycle_result.h"

namespace kivo::playback::orchestration {
void run_playback_lifecycle_tests() {
    PlaybackLifecycleState s1 = PlaybackLifecycleState::Idle;
    PlaybackLifecycleState s2 = PlaybackLifecycleState::Opening;
    PlaybackLifecycleState s3 = PlaybackLifecycleState::Ready;
    PlaybackLifecycleState s4 = PlaybackLifecycleState::Playing;
    PlaybackLifecycleState s5 = PlaybackLifecycleState::Paused;
    PlaybackLifecycleState s6 = PlaybackLifecycleState::Stopping;
    PlaybackLifecycleState s7 = PlaybackLifecycleState::Stopped;
    PlaybackLifecycleState s8 = PlaybackLifecycleState::Failed;
    assert(s1 != s2); assert(s2 != s3); assert(s3 != s4);
    assert(s4 != s5); assert(s5 != s6); assert(s6 != s7); assert(s7 != s8);

    PlaybackLifecycleRequestKind k1 = PlaybackLifecycleRequestKind::Open;
    PlaybackLifecycleRequestKind k2 = PlaybackLifecycleRequestKind::Play;
    PlaybackLifecycleRequestKind k3 = PlaybackLifecycleRequestKind::Pause;
    PlaybackLifecycleRequestKind k4 = PlaybackLifecycleRequestKind::Stop;
    PlaybackLifecycleRequestKind k5 = PlaybackLifecycleRequestKind::Close;
    assert(k1 != k2); assert(k2 != k3); assert(k3 != k4); assert(k4 != k5);

    PlaybackLifecycleTransition t1;
    assert(t1.session_id.value == 0);
    assert(t1.previous == PlaybackLifecycleState::Unknown);
    assert(t1.request == PlaybackLifecycleRequestKind::Unknown);
    assert(t1.next == PlaybackLifecycleState::Unknown);
    PlaybackLifecycleTransition t2{
        .session_id{PlaybackSessionId{100}},
        .previous{PlaybackLifecycleState::Ready},
        .request{PlaybackLifecycleRequestKind::Play},
        .next{PlaybackLifecycleState::Playing}
    };
    assert(t2.previous == PlaybackLifecycleState::Ready);
    assert(t2.next == PlaybackLifecycleState::Playing);

    PlaybackLifecycleResult result1;
    assert(result1.session_id.value == 0);
    assert(result1.resulting_state == PlaybackLifecycleState::Unknown);
    PlaybackLifecycleResult result2{.session_id{PlaybackSessionId{200}}, .resulting_state{PlaybackLifecycleState::Playing}};
    assert(result2.resulting_state == PlaybackLifecycleState::Playing);

    std::cout << "  playback_lifecycle_tests: ALL PASSED\n";
}
}
