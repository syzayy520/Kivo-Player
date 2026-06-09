// tests/unit/core/playback_state_machine_tests.cpp
#include "core/state/playback_state_machine.h"
#include <cstdio>

namespace kivo::playback {

static int check_count = 0;
static int fail_count = 0;

static auto check(bool cond, const char* msg) -> void {
    ++check_count;
    if (!cond) { ++fail_count; printf("[FAIL] %s\n", msg); }
}

static auto report() -> int {
    printf("[%s] state_machine_tests: %d checks\n",
           fail_count == 0 ? "PASS" : "FAIL", check_count);
    return fail_count == 0 ? 0 : 1;
}

} // namespace

int main() {
    using namespace kivo::playback;
    check_count = 0; fail_count = 0;

    // Idle -> Opening allowed
    {
        PlaybackStateMachine sm;
        auto r = sm.try_transition(PlaybackState::Opening);
        check(r.is_success(), "Idle->Opening allowed");
        check(sm.current_state() == PlaybackState::Opening, "state is Opening");
    }
    // Opening -> Ready allowed (P0-001 synthetic shortcut)
    {
        PlaybackStateMachine sm; sm.try_transition(PlaybackState::Opening);
        auto r = sm.try_transition(PlaybackState::Ready);
        check(r.is_success(), "Opening->Ready allowed");
    }
    // Ready -> Playing allowed
    {
        PlaybackStateMachine sm; sm.try_transition(PlaybackState::Opening); sm.try_transition(PlaybackState::Ready);
        auto r = sm.try_transition(PlaybackState::Playing);
        check(r.is_success(), "Ready->Playing allowed");
    }
    // Playing -> Paused allowed
    {
        PlaybackStateMachine sm; sm.try_transition(PlaybackState::Opening); sm.try_transition(PlaybackState::Ready); sm.try_transition(PlaybackState::Playing);
        auto r = sm.try_transition(PlaybackState::Paused);
        check(r.is_success(), "Playing->Paused allowed");
    }
    // Paused -> Playing allowed
    {
        PlaybackStateMachine sm; /* setup to Paused ... */
        auto r = sm.try_transition(PlaybackState::Opening); r = sm.try_transition(PlaybackState::Ready); r = sm.try_transition(PlaybackState::Playing); r = sm.try_transition(PlaybackState::Paused);
        r = sm.try_transition(PlaybackState::Playing);
        check(r.is_success(), "Paused->Playing allowed");
    }
    // Closed -> Playing rejected
    {
        PlaybackStateMachine sm; sm.try_transition(PlaybackState::Opening); sm.try_transition(PlaybackState::Ready); sm.try_transition(PlaybackState::Playing); sm.try_transition(PlaybackState::Ended); sm.try_transition(PlaybackState::Idle); sm.try_transition(PlaybackState::Opening); sm.try_transition(PlaybackState::Closing); sm.try_transition(PlaybackState::Closed);
        auto r = sm.try_transition(PlaybackState::Playing);
        check(r.is_failure(), "Closed->Playing rejected");
        check(!r.is_success(), "Closed->Playing not success");
    }
    // Idle -> Paused rejected
    {
        PlaybackStateMachine sm;
        auto r = sm.try_transition(PlaybackState::Paused);
        check(r.is_failure(), "Idle->Paused rejected");
    }

    return report();
}
