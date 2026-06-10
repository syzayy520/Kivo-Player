// Copyright (c) 2026 Kivo Project. All rights reserved.
// tests/pipeline/contracts/flow_contract_tests.cpp - Flow contract tests.

#include "pipeline/contracts/flow/discontinuity.h"
#include "pipeline/contracts/flow/end_of_stream.h"
#include "pipeline/contracts/flow/backpressure.h"
#include "pipeline/contracts/flow/generation.h"
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

void test_discontinuity_info() {
    kivo::pipeline::flow::discontinuity::DiscontinuityInfo info;
    info.type = kivo::pipeline::flow::discontinuity::DiscontinuityType::TimeJump;
    info.new_time = kivo::playback::MediaTime{60000};
    info.old_time = kivo::playback::MediaTime{50000};
    CHECK(info.type == kivo::pipeline::flow::discontinuity::DiscontinuityType::TimeJump);
    CHECK(info.new_time == 60000);
}

void test_end_of_stream_signal() {
    kivo::pipeline::flow::end_of_stream::EndOfStreamSignal sig;
    sig.session_id = kivo::playback::SessionId{1};
    sig.stream_index = 0;
    sig.last_pts_ms = 300000;
    CHECK(sig.session_id.value == 1);
    CHECK(sig.last_pts_ms == 300000);
}

void test_backpressure_signal() {
    kivo::pipeline::flow::backpressure::BackpressureSignal sig;
    sig.level = kivo::pipeline::flow::backpressure::BackpressureLevel::Soft;
    sig.current_packets = 500;
    CHECK(sig.level == kivo::pipeline::flow::backpressure::BackpressureLevel::Soft);
    CHECK(sig.current_packets == 500);
}

void test_backpressure_level_canonical() {
    using kivo::pipeline::flow::backpressure::BackpressureLevel;
    // Verify all canonical enum values exist
    auto l_none = BackpressureLevel::None;
    auto l_soft = BackpressureLevel::Soft;
    auto l_hard = BackpressureLevel::Hard;
    auto l_overflow = BackpressureLevel::Overflow;
    CHECK(l_none != l_overflow);
    CHECK(static_cast<int>(l_soft) > static_cast<int>(l_none));
    CHECK(static_cast<int>(l_hard) > static_cast<int>(l_soft));
    CHECK(static_cast<int>(l_overflow) > static_cast<int>(l_hard));
}

void test_generation_token() {
    kivo::pipeline::flow::generation::GenerationToken token;
    token.id = kivo::playback::GenerationId{42};
    CHECK(token.id.value == 42);
    CHECK(token.is_valid());
}
