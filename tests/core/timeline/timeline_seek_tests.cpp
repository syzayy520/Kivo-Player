// Copyright (c) 2026 Kivo Project. All rights reserved.
// tests/core/timeline/timeline_seek_tests.cpp
// Tests: seek/seek_target.h, seek/preroll.h, reset/timeline_reset.h

#include "core/timeline/seek/seek_target.h"
#include "core/timeline/seek/preroll.h"
#include "core/timeline/reset/timeline_reset.h"
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

static void test_seek_mode() {
    using namespace kivo::playback::timeline;
    CHECK(SeekMode::KeyframeOnly != SeekMode::Accurate);
    CHECK(SeekMode::Fast != SeekMode::Preview);
}

static void test_seek_target() {
    using namespace kivo::playback::timeline;
    SeekTarget target;
    target.mode = SeekMode::Accurate;
    target.accuracy = SeekAccuracyHint::Exact;
    CHECK(target.mode == SeekMode::Accurate);
    CHECK(target.accuracy == SeekAccuracyHint::Exact);
}

static void test_preroll_policy() {
    using namespace kivo::playback::timeline;
    CHECK(PrerollPolicy::None != PrerollPolicy::Adaptive);
    CHECK(PrerollPolicy::KeyframeToTarget != PrerollPolicy::FixedFrames);
}

static void test_preroll_requirements() {
    using namespace kivo::playback::timeline;
    PrerollRequirements req;
    req.min_frames = 2;
    req.max_frames = 10;
    req.keyframe_required = true;
    CHECK(req.min_frames == 2);
    CHECK(req.max_frames == 10);
    CHECK(req.keyframe_required);
}

static void test_timeline_reset_reason() {
    using namespace kivo::playback::timeline;
    CHECK(TimelineResetReason::Seek != TimelineResetReason::Recovery);
    CHECK(TimelineResetReason::StreamSwitch != TimelineResetReason::UserDefined);
}

static void test_timeline_reset_scope() {
    using namespace kivo::playback::timeline;
    CHECK(TimelineResetScope::SingleStream != TimelineResetScope::SessionScoped);
}

static void test_timeline_reset_action() {
    using namespace kivo::playback::timeline;
    CHECK(TimelineResetAction::ClearSegments != TimelineResetAction::PreserveHistory);
}

int run_timeline_seek_tests() {
    test_seek_mode();
    test_seek_target();
    test_preroll_policy();
    test_preroll_requirements();
    test_timeline_reset_reason();
    test_timeline_reset_scope();
    test_timeline_reset_action();
    return 0;
}
