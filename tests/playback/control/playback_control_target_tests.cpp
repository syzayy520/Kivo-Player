#include <cassert>
#include <iostream>
#include "playback/control/target/playback_control_target_kind.h"
#include "playback/control/target/playback_session_target.h"
#include "playback/control/target/playback_seek_target.h"
#include "playback/control/target/playback_control_target.h"
namespace kivo::playback::control {
void run_playback_control_target_tests() {
    PlaybackControlTargetKind k1 = PlaybackControlTargetKind::Session; PlaybackControlTargetKind k2 = PlaybackControlTargetKind::Seek;
    assert(k1 != k2);
    PlaybackSessionTarget st1;
    assert(st1.request_id.value == 0); assert(st1.session_id.value == 0);
    PlaybackSessionTarget st2{.request_id{ControlRequestId{10}}, .session_id{kivo::playback::orchestration::PlaybackSessionId{100}}};
    assert(st2.session_id.value == 100);
    PlaybackSeekTarget sk1;
    assert(sk1.request_id.value == 0); assert(sk1.session_id.value == 0); assert(sk1.target_position.value == 0);
    PlaybackSeekTarget sk2{.request_id{ControlRequestId{20}}, .session_id{kivo::playback::orchestration::PlaybackSessionId{200}}, .target_position{kivo::playback::timeline::MediaTimestamp{{}, 50000}}};
    assert(sk2.target_position.value == 50000);
    PlaybackControlTarget t1;
    assert(t1.kind == PlaybackControlTargetKind::Unknown);
    PlaybackControlTarget t2{.kind{PlaybackControlTargetKind::Seek}, .session_target{st2}, .seek_target{sk2}};
    assert(t2.seek_target.target_position.value == 50000);
    std::cout << "  playback_control_target_tests: ALL PASSED\n";
}
}
