#include <cassert>
#include <iostream>
#include "playback/control/identity/control_command_id.h"
#include "playback/control/identity/control_sequence_id.h"
#include "playback/control/identity/control_request_id.h"
#include "playback/control/identity/control_identity.h"
namespace kivo::playback::control {
void run_control_identity_tests() {
    ControlCommandId cid1; assert(cid1.value == 0); ControlCommandId cid2{42}; assert(cid2.value == 42);
    ControlSequenceId sid1; assert(sid1.value == 0); ControlSequenceId sid2{7}; assert(sid2.value == 7);
    ControlRequestId rid1; assert(rid1.value == 0); ControlRequestId rid2{99}; assert(rid2.value == 99);
    ControlIdentity ident1;
    assert(ident1.command_id.value == 0); assert(ident1.sequence_id.value == 0); assert(ident1.request_id.value == 0);
    ControlIdentity ident2{.command_id{1}, .sequence_id{2}, .request_id{3}};
    assert(ident2.command_id.value == 1); assert(ident2.sequence_id.value == 2); assert(ident2.request_id.value == 3);
    std::cout << "  control_identity_tests: ALL PASSED\n";
}
void run_control_source_tests();
void run_playback_control_command_tests();
void run_playback_control_target_tests();
void run_control_normalization_tests();
void run_control_outcome_tests();
}
int main() {
    using namespace kivo::playback::control;
    run_control_identity_tests(); run_control_source_tests();
    run_playback_control_command_tests(); run_playback_control_target_tests();
    run_control_normalization_tests(); run_control_outcome_tests();
    std::cout << "  ALL playback control tests PASSED\n"; return 0;
}
