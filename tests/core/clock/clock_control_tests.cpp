// Copyright (c) 2026 Kivo Project. All rights reserved.
// tests/core/clock/clock_control_tests.cpp
// Tests: control/pause_resume_clock.h, control/seek_clock_reset.h, control/eos_clock_coordination.h

#include "core/clock/control/pause_resume_clock.h"
#include "core/clock/control/seek_clock_reset.h"
#include "core/clock/control/eos_clock_coordination.h"
#include <iostream>

extern int g_passed_checks;
extern int g_failed_checks;

#define CHECK(cond) \
    do { \
        if (!(cond)) { \
            ++g_failed_checks; \
            std::cerr << "FAILED: " << __FILE__ << ":" << __LINE__ << ": " << #cond << std::endl; \
        } else { \
            ++g_passed_checks; \
        } \
    } while(0)

// --- pause_resume tests ---
static void test_pause_resume_clock_state() {
    using namespace kivo::playback::clock;
    CHECK(PauseResumeClockState::Running != PauseResumeClockState::Paused);
    CHECK(PauseResumeClockState::Pausing != PauseResumeClockState::Resuming);
}

static void test_pause_clock_record() {
    using namespace kivo::playback::clock;
    PauseClockRecord rec;
    rec.accumulated_pause_us = 500000;
    CHECK(rec.accumulated_pause_us == 500000);
}

// --- seek_clock_reset tests ---
static void test_seek_clock_reset() {
    using namespace kivo::playback::clock;
    SeekClockReset reset;
    reset.reset_reason = kivo::playback::timeline::TimelineResetReason::Seek;
    CHECK(reset.reset_reason == kivo::playback::timeline::TimelineResetReason::Seek);
    CHECK(SeekResetAction::FlushObservations != SeekResetAction::FullReset);
}

// --- eos_clock_coordination tests ---
static void test_eos_participant_set() {
    using namespace kivo::playback::clock;
    EosClockParticipantSet ps;
    ps.timeline = true;
    ps.master_clock = true;
    CHECK(ps.timeline);
    CHECK(ps.master_clock);
    CHECK(!ps.projection);
}

static void test_eos_clock_state() {
    using namespace kivo::playback::clock;
    CHECK(EosClockState::NotReached != EosClockState::Coordinated);
    CHECK(EosClockState::Detected != EosClockState::Timeout);
}

static void test_eos_timeout_policy() {
    using namespace kivo::playback::clock;
    CHECK(EosClockTimeoutPolicy::HoldLastProjection != EosClockTimeoutPolicy::MarkProjectionInvalid);
}

static void test_eos_clock_coordination() {
    using namespace kivo::playback::clock;
    EosClockCoordination coord;
    coord.state = EosClockState::Coordinating;
    coord.participants.timeline = true;
    coord.timeout_us = 100000;
    coord.timeout_policy = EosClockTimeoutPolicy::HoldLastProjection;
    CHECK(coord.state == EosClockState::Coordinating);
    CHECK(coord.participants.timeline);
    CHECK(coord.timeout_us == 100000);
    CHECK(coord.timeout_policy == EosClockTimeoutPolicy::HoldLastProjection);
}

int run_clock_control_tests() {
    test_pause_resume_clock_state();
    test_pause_clock_record();
    test_seek_clock_reset();
    test_eos_participant_set();
    test_eos_clock_state();
    test_eos_timeout_policy();
    test_eos_clock_coordination();
    return 0;
}
