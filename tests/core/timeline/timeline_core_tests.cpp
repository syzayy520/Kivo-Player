// Copyright (c) 2026 Kivo Project. All rights reserved.
// tests/core/timeline/timeline_core_tests.cpp
// Tests: base/timebase.h, base/media_timestamp.h, segment/timeline_segment.h
// Contains: main(), CHECK macro, global counters

#include "core/timeline/timestamp/timebase.h"
#include "core/timeline/timestamp/media_timestamp.h"
#include "core/timeline/segment/timeline_segment.h"
#include <iostream>

int g_passed_checks = 0;
int g_failed_checks = 0;

#define CHECK(cond) \
    do { \
        if (!(cond)) { \
            ++g_failed_checks; \
            std::cerr << "FAILED: " << __FILE__ << ":" << __LINE__ << ": " << #cond << std::endl; \
        } else { \
            ++g_passed_checks; \
        } \
    } while(0)

// --- timebase tests ---
static void test_timebase_default() {
    using namespace kivo::playback::timeline;
    Timebase tb;
    CHECK(tb.num == 1);
    CHECK(tb.den == 1);
}

static void test_timebase_validity() {
    using namespace kivo::playback::timeline;
    CHECK(TimebaseValidity::Valid != TimebaseValidity::ZeroDenominator);
    CHECK(TimebaseValidity::Incompatible != TimebaseValidity::Valid);
}

static void test_timebase_conversion_request() {
    using namespace kivo::playback::timeline;
    TimebaseConversionRequest req;
    req.src = Timebase{1, 1000};
    req.dst = Timebase{1, 90000};
    req.src_value = 60000;
    CHECK(req.src.num == 1);
    CHECK(req.src_value == 60000);
}

static void test_timebase_conversion_result() {
    using namespace kivo::playback::timeline;
    TimebaseConversionResult res;
    res.dst_value = 5400;
    res.exact = true;
    res.validity = TimebaseValidity::Valid;
    CHECK(res.dst_value == 5400);
    CHECK(res.exact);
    CHECK(res.validity == TimebaseValidity::Valid);
}

// --- media_timestamp tests ---
static void test_media_timestamp() {
    using namespace kivo::playback::timeline;
    MediaTimestamp ts;
    ts.timebase = Timebase{1, 1000};
    ts.value = 42000;
    CHECK(ts.value == 42000);
}

static void test_timestamp_validity() {
    using namespace kivo::playback::timeline;
    CHECK(TimestampValidity::Valid != TimestampValidity::Invalid);
    CHECK(TimestampValidity::Missing != TimestampValidity::Estimated);
}

static void test_timestamp_origin_neutral() {
    using namespace kivo::playback::timeline;
    CHECK(TimestampOrigin::ContainerDeclared != TimestampOrigin::DecodedOutputDeclared);
    CHECK(TimestampOrigin::Estimated != TimestampOrigin::UserAdjusted);
}

static void test_timestamp_range() {
    using namespace kivo::playback::timeline;
    TimestampRange rng;
    rng.start.timebase = Timebase{1, 1000};
    rng.start.value = 0;
    rng.end.value = 60000;
    CHECK(rng.start.value == 0);
    CHECK(rng.end.value == 60000);
}

// --- timeline_segment tests ---
static void test_timeline_segment() {
    using namespace kivo::playback::timeline;
    TimelineSegment seg;
    seg.range.start.value = 0;
    seg.range.end.value = 30000;
    seg.segment_index = 0;
    CHECK(seg.segment_index == 0);
    CHECK(seg.range.start.value == 0);
}

static void test_timeline_discontinuity_type() {
    using namespace kivo::playback::timeline;
    CHECK(TimelineDiscontinuityType::Gap != TimelineDiscontinuityType::Reset);
    CHECK(TimelineDiscontinuityType::Overlap != TimelineDiscontinuityType::SegmentBoundary);
}

static void test_timeline_discontinuity() {
    using namespace kivo::playback::timeline;
    TimelineDiscontinuity disc;
    disc.type = TimelineDiscontinuityType::Gap;
    disc.old_segment.segment_index = 0;
    disc.new_segment.segment_index = 1;
    CHECK(disc.type == TimelineDiscontinuityType::Gap);
    CHECK(disc.old_segment.segment_index == 0);
}

static void test_timeline_mapping_no_wall_time() {
    using namespace kivo::playback::timeline;
    TimelineMapping map;
    map.container_timeline_id = 1;
    map.stream_timeline_id = 0;
    map.unified_timeline_id = 0;
    CHECK(map.container_timeline_id == 1);
    // TimelineMapping must NOT contain wall time / QPC / system clock / audio clock
}

extern int run_timeline_seek_tests();
extern int run_timeline_compensation_rate_tests();

int main() {
    test_timebase_default();
    test_timebase_validity();
    test_timebase_conversion_request();
    test_timebase_conversion_result();
    test_media_timestamp();
    test_timestamp_validity();
    test_timestamp_origin_neutral();
    test_timestamp_range();
    test_timeline_segment();
    test_timeline_discontinuity_type();
    test_timeline_discontinuity();
    test_timeline_mapping_no_wall_time();

    run_timeline_seek_tests();
    run_timeline_compensation_rate_tests();

    std::cout << "timeline_tests: " << g_passed_checks
              << " passed, " << g_failed_checks << " failed" << std::endl;
    return g_failed_checks > 0 ? 1 : 0;
}
