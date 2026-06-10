// Copyright (c) 2026 Kivo Project. All rights reserved.
// tests/pipeline/model/packet_flow/lifecycle_control_flow_tests.cpp
// Tests: lifecycle_flow.h, cancellation_flow.h

#include "pipeline/model/packet_flow/lifecycle_flow.h"
#include "pipeline/model/packet_flow/cancellation_flow.h"
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

// --- lifecycle_flow tests ---
static void test_lifecycle_command_status() {
    using namespace kivo::pipeline::model::packet_flow;
    CHECK(LifecycleCommandStatus::Pending != LifecycleCommandStatus::Completed);
    CHECK(LifecycleCommandStatus::Active != LifecycleCommandStatus::Aborted);
}

static void test_lifecycle_stage_mask() {
    using namespace kivo::pipeline::model::packet_flow;
    LifecycleStageMask mask;
    mask.demux_stage = true;
    mask.decode_stage = false;
    mask.output_stage = false;
    CHECK(mask.demux_stage);
    CHECK(!mask.decode_stage);
}

static void test_flush_flow_mode() {
    using namespace kivo::pipeline::model::packet_flow;
    CHECK(FlushFlowMode::DiscardPending != FlushFlowMode::HardReset);
}

static void test_drain_flow_mode() {
    using namespace kivo::pipeline::model::packet_flow;
    CHECK(DrainFlowMode::BlockUntilEmpty != DrainFlowMode::Immediate);
}

static void test_seek_lifecycle_rule() {
    using namespace kivo::pipeline::model::packet_flow;
    SeekLifecycleRule rule;
    rule.eos_before = true;
    rule.flush_between = true;
    rule.eos_after = true;
    CHECK(rule.eos_before);
    CHECK(rule.flush_between);
    CHECK(rule.eos_after);
}

// --- cancellation_flow tests ---
static void test_cancellation_scope() {
    using namespace kivo::pipeline::model::packet_flow;
    CHECK(CancellationScope::StreamScoped != CancellationScope::PipelineScoped);
    CHECK(CancellationScope::SessionScoped != CancellationScope::Unknown);
}

static void test_cancellation_stage() {
    using namespace kivo::pipeline::model::packet_flow;
    CHECK(CancellationStage::Requested != CancellationStage::Completed);
    CHECK(CancellationStage::Propagating != CancellationStage::Draining);
}

static void test_cancellation_flow_rule() {
    using namespace kivo::pipeline::model::packet_flow;
    CHECK(CancellationFlowRule::DrainCompletion != CancellationFlowRule::ImmediateStop);
    CHECK(CancellationFlowRule::CleanShutdown != CancellationFlowRule::Unknown);
}

static void test_cancellation_flow_result() {
    using namespace kivo::pipeline::model::packet_flow;
    CHECK(CancellationFlowResult::Cancelled != CancellationFlowResult::PartiallyCancelled);
}

// --- test runner ---
int run_lifecycle_control_flow_tests() {
    test_lifecycle_command_status();
    test_lifecycle_stage_mask();
    test_flush_flow_mode();
    test_drain_flow_mode();
    test_seek_lifecycle_rule();
    test_cancellation_scope();
    test_cancellation_stage();
    test_cancellation_flow_rule();
    test_cancellation_flow_result();
    return 0;
}
