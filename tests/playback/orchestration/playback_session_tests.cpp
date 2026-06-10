#include <cassert>
#include <iostream>
#include "playback/orchestration/session/playback_session_id.h"
#include "playback/orchestration/session/playback_session_generation.h"
#include "playback/orchestration/session/playback_session_role.h"
#include "playback/orchestration/session/playback_session_identity.h"

namespace kivo::playback::orchestration {
void run_playback_session_tests() {
    PlaybackSessionId id1;
    assert(id1.value == 0);
    PlaybackSessionId id2{42};
    assert(id2.value == 42);

    PlaybackSessionGeneration gen1;
    assert(gen1.value == 0);
    PlaybackSessionGeneration gen2{7};
    assert(gen2.value == 7);

    PlaybackSessionRole r1 = PlaybackSessionRole::Primary;
    PlaybackSessionRole r2 = PlaybackSessionRole::Preview;
    PlaybackSessionRole r3 = PlaybackSessionRole::Background;
    assert(r1 != r2); assert(r2 != r3);

    PlaybackSessionIdentity ident1;
    assert(ident1.session_id.value == 0);
    assert(ident1.generation.value == 0);
    assert(ident1.role == PlaybackSessionRole::Unknown);
    assert(ident1.scenario_ref.value == 0);
    PlaybackSessionIdentity ident2{
        .session_id{100}, .generation{1},
        .role{PlaybackSessionRole::Primary},
        .scenario_ref{kivo::playback::scenario::ScenarioId{999}}
    };
    assert(ident2.session_id.value == 100);
    assert(ident2.role == PlaybackSessionRole::Primary);
    assert(ident2.scenario_ref.value == 999);

    std::cout << "  playback_session_tests: ALL PASSED\n";
}
void run_playback_lifecycle_tests();
void run_playback_intent_tests();
void run_playback_timeline_tests();
void run_playback_binding_tests();
void run_playback_outcome_tests();
}

int main() {
    using namespace kivo::playback::orchestration;
    run_playback_session_tests();
    run_playback_lifecycle_tests();
    run_playback_intent_tests();
    run_playback_timeline_tests();
    run_playback_binding_tests();
    run_playback_outcome_tests();
    std::cout << "  ALL playback orchestration tests PASSED\n";
    return 0;
}
