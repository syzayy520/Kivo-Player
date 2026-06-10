#include <cassert>
#include <iostream>
#include "playback/control/command/playback_control_command_kind.h"
#include "playback/control/command/playback_control_priority.h"
#include "playback/control/command/playback_control_ordering.h"
#include "playback/control/command/playback_control_command.h"
namespace kivo::playback::control {
void run_playback_control_command_tests() {
    PlaybackControlCommandKind k1 = PlaybackControlCommandKind::Open; PlaybackControlCommandKind k2 = PlaybackControlCommandKind::Play;
    PlaybackControlCommandKind k3 = PlaybackControlCommandKind::Pause; PlaybackControlCommandKind k4 = PlaybackControlCommandKind::Stop; PlaybackControlCommandKind k5 = PlaybackControlCommandKind::Seek;
    assert(k1 != k2); assert(k2 != k3); assert(k3 != k4); assert(k4 != k5);
    PlaybackControlPriority p1 = PlaybackControlPriority::Low; PlaybackControlPriority p2 = PlaybackControlPriority::Normal;
    PlaybackControlPriority p3 = PlaybackControlPriority::High; PlaybackControlPriority p4 = PlaybackControlPriority::Critical;
    assert(p1 != p2); assert(p2 != p3); assert(p3 != p4);
    PlaybackControlOrdering o1 = PlaybackControlOrdering::Immediate; PlaybackControlOrdering o2 = PlaybackControlOrdering::Ordered; PlaybackControlOrdering o3 = PlaybackControlOrdering::LatestOnly;
    assert(o1 != o2); assert(o2 != o3);
    PlaybackControlCommand cmd1;
    assert(cmd1.kind == PlaybackControlCommandKind::Unknown); assert(cmd1.priority == PlaybackControlPriority::Unknown);
    PlaybackControlCommand cmd2{.identity{.command_id{1}, .sequence_id{2}, .request_id{3}}, .kind{PlaybackControlCommandKind::Play}, .priority{PlaybackControlPriority::High}, .ordering{PlaybackControlOrdering::Immediate}};
    assert(cmd2.kind == PlaybackControlCommandKind::Play); assert(cmd2.priority == PlaybackControlPriority::High);
    std::cout << "  playback_control_command_tests: ALL PASSED\n";
}
}
