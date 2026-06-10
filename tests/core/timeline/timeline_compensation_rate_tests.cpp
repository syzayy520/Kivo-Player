// Copyright (c) 2026 Kivo Project. All rights reserved.
// tests/core/timeline/timeline_compensation_rate_tests.cpp
// Tests: mapping/track_offset.h, mapping/track_delay_compensation.h, mapping/rate_timestamp_mapping.h

#include "core/timeline/mapping/track_offset.h"
#include "core/timeline/mapping/track_delay_compensation.h"
#include "core/timeline/mapping/rate_timestamp_mapping.h"
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

static void test_track_offset_direction() {
    using namespace kivo::playback::timeline;
    CHECK(TrackOffsetDirection::Advance != TrackOffsetDirection::Delay);
}

static void test_track_offset_adjustment() {
    using namespace kivo::playback::timeline;
    TrackOffsetAdjustment adj;
    adj.track_id = kivo::playback::TrackId{0};
    adj.offset_us = 50000;
    adj.direction = TrackOffsetDirection::Delay;
    CHECK(adj.offset_us == 50000);
    CHECK(adj.direction == TrackOffsetDirection::Delay);
}

static void test_compensation_source() {
    using namespace kivo::playback::timeline;
    CHECK(CompensationSource::UserConfigured != CompensationSource::Measured);
}

static void test_track_delay_compensation() {
    using namespace kivo::playback::timeline;
    TrackDelayCompensation comp;
    comp.track_id = kivo::playback::TrackId{1};
    comp.delay_us = 20000;
    comp.mode = CompensationMode::TrackAheadOfReference;
    CHECK(comp.delay_us == 20000);
    CHECK(comp.mode == CompensationMode::TrackAheadOfReference);
}

static void test_rate_change_point() {
    using namespace kivo::playback::timeline;
    RateChangePoint rp;
    rp.old_rate = 1.0;
    rp.new_rate = 2.0;
    CHECK(rp.old_rate == 1.0);
    CHECK(rp.new_rate == 2.0);
}

static void test_rate_timestamp_mapping_rule() {
    using namespace kivo::playback::timeline;
    RateTimestampMappingRule rule;
    rule.resample_timestamps = true;
    rule.preserve_duration = false;
    CHECK(rule.resample_timestamps);
    CHECK(!rule.preserve_duration);
}

int run_timeline_compensation_rate_tests() {
    test_track_offset_direction();
    test_track_offset_adjustment();
    test_compensation_source();
    test_track_delay_compensation();
    test_rate_change_point();
    test_rate_timestamp_mapping_rule();
    return 0;
}
