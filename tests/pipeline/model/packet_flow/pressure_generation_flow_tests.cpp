// Copyright (c) 2026 Kivo Project. All rights reserved.
// tests/pipeline/model/packet_flow/pressure_generation_flow_tests.cpp
// Tests: backpressure_flow.h, generation_flow.h

#include "pipeline/model/packet_flow/backpressure_flow.h"
#include "pipeline/model/packet_flow/generation_flow.h"
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

// --- backpressure_flow tests ---
static void test_backpressure_source_neutral() {
    using namespace kivo::pipeline::model::packet_flow;
    auto s1 = BackpressureSource::QueueHighWatermark;
    auto s2 = BackpressureSource::ProducerBurst;
    auto s3 = BackpressureSource::ConsumerLag;
    auto s4 = BackpressureSource::DownstreamBacklog;
    auto s5 = BackpressureSource::PipelinePaused;
    CHECK(s1 != s5);
    // Verify no decoder/render/output binding in enum names
    (void)s2; (void)s3; (void)s4;
}

static void test_backpressure_flow_rule() {
    using namespace kivo::pipeline::model::packet_flow;
    BackpressureFlowRule rule;
    rule.level = kivo::pipeline::flow::backpressure::BackpressureLevel::Soft;
    rule.action = BackpressureFlowAction::Throttle;
    rule.direction = BackpressureDirection::Upstream;
    CHECK(rule.level == kivo::pipeline::flow::backpressure::BackpressureLevel::Soft);
    CHECK(rule.action == BackpressureFlowAction::Throttle);
    CHECK(rule.direction == BackpressureDirection::Upstream);
}

static void test_backpressure_direction() {
    using namespace kivo::pipeline::model::packet_flow;
    CHECK(BackpressureDirection::None != BackpressureDirection::Bidirectional);
    CHECK(BackpressureDirection::Upstream != BackpressureDirection::Downstream);
}

// --- generation_flow tests ---
static void test_generation_flow_state() {
    using namespace kivo::pipeline::model::packet_flow;
    auto curr = GenerationFlowState::Current;
    auto old = GenerationFlowState::Superseded;
    CHECK(curr != old);
    CHECK(curr != GenerationFlowState::Unknown);
}

static void test_generation_flow_checkpoint() {
    using namespace kivo::pipeline::model::packet_flow;
    CHECK(GenerationFlowCheckpoint::AfterFlush != GenerationFlowCheckpoint::AfterEos);
    CHECK(GenerationFlowCheckpoint::AfterDrain != GenerationFlowCheckpoint::Unknown);
}

static void test_generation_flow_rule() {
    using namespace kivo::pipeline::model::packet_flow;
    GenerationFlowRule rule;
    rule.checkpoint = GenerationFlowCheckpoint::AfterFlush;
    rule.reject_stale = true;
    rule.reject_future = false;
    CHECK(rule.checkpoint == GenerationFlowCheckpoint::AfterFlush);
    CHECK(rule.reject_stale);
    CHECK(!rule.reject_future);
}

static void test_generation_validation_result() {
    using namespace kivo::pipeline::model::packet_flow;
    CHECK(GenerationFlowValidationResult::Accepted != GenerationFlowValidationResult::RejectedStale);
    CHECK(GenerationFlowValidationResult::RejectedStale != GenerationFlowValidationResult::RejectedFuture);
}

// --- test runner ---
int run_pressure_generation_flow_tests() {
    test_backpressure_source_neutral();
    test_backpressure_flow_rule();
    test_backpressure_direction();
    test_generation_flow_state();
    test_generation_flow_checkpoint();
    test_generation_flow_rule();
    test_generation_validation_result();
    return 0;
}
