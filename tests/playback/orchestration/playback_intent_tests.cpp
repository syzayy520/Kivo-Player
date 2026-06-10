#include <cassert>
#include <iostream>
#include "playback/orchestration/intent/playback_intent_id.h"
#include "playback/orchestration/intent/playback_intent_kind.h"
#include "playback/orchestration/intent/playback_intent.h"
#include "playback/orchestration/intent/playback_intent_result.h"

namespace kivo::playback::orchestration {
void run_playback_intent_tests() {
    PlaybackIntentId id1;
    assert(id1.value == 0);
    PlaybackIntentId id2{777};
    assert(id2.value == 777);

    PlaybackIntentKind k1 = PlaybackIntentKind::Open;
    PlaybackIntentKind k2 = PlaybackIntentKind::Play;
    PlaybackIntentKind k3 = PlaybackIntentKind::Pause;
    PlaybackIntentKind k4 = PlaybackIntentKind::Stop;
    PlaybackIntentKind k5 = PlaybackIntentKind::Seek;
    assert(k1 != k2); assert(k2 != k3); assert(k3 != k4); assert(k4 != k5);

    PlaybackIntent intent1;
    assert(intent1.intent_id.value == 0);
    assert(intent1.kind == PlaybackIntentKind::Unknown);
    assert(intent1.session_id.value == 0);
    PlaybackIntent intent2{.intent_id{300}, .kind{PlaybackIntentKind::Play}, .session_id{PlaybackSessionId{100}}};
    assert(intent2.kind == PlaybackIntentKind::Play);
    assert(intent2.session_id.value == 100);

    PlaybackIntentResult result1;
    assert(result1.intent_id.value == 0);
    assert(result1.status == PlaybackOrchestrationStatus::Unknown);
    PlaybackIntentResult result2{.intent_id{400}, .status{PlaybackOrchestrationStatus::Active}};
    assert(result2.status == PlaybackOrchestrationStatus::Active);

    std::cout << "  playback_intent_tests: ALL PASSED\n";
}
}
