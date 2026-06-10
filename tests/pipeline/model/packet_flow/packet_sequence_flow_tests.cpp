// Copyright (c) 2026 Kivo Project. All rights reserved.
// tests/pipeline/model/packet_flow/packet_sequence_flow_tests.cpp
// Tests: packet_sequence.h, eos_flow.h, discontinuity_flow.h
// Contains: main(), CHECK macro, global counters

#include "pipeline/model/packet_flow/packet_sequence.h"
#include "pipeline/model/packet_flow/eos_flow.h"
#include "pipeline/model/packet_flow/discontinuity_flow.h"
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

// --- packet_sequence tests ---
static void test_packet_sequence_order() {
    using namespace kivo::pipeline::model::packet_flow;
    CHECK(SequenceOrder::Sequential != SequenceOrder::OutOfOrder);
    CHECK(SequenceOrder::Gap != SequenceOrder::Unknown);
}

static void test_sequence_validation_result() {
    using namespace kivo::pipeline::model::packet_flow;
    CHECK(SequenceValidationResult::Valid != SequenceValidationResult::Duplicate);
    CHECK(SequenceValidationResult::OutOfOrder != SequenceValidationResult::GapDetected);
}

static void test_sequence_check_policy() {
    using namespace kivo::pipeline::model::packet_flow;
    CHECK(SequenceCheckPolicy::StrictForward != SequenceCheckPolicy::BestEffort);
}

static void test_packet_stream_position() {
    using namespace kivo::pipeline::model::packet_flow;
    PacketStreamPosition pos;
    pos.track_id = kivo::playback::TrackId{1};
    pos.seq_number = 42;
    pos.pts = 1000;
    pos.dts = 900;
    CHECK(pos.track_id.value == 1);
    CHECK(pos.seq_number == 42);
    CHECK(pos.pts == 1000);
    CHECK(pos.dts == 900);
}

// --- eos_flow tests ---
static void test_eos_pipeline_stage() {
    using namespace kivo::pipeline::model::packet_flow;
    CHECK(EosPipelineStage::DemuxEnd != EosPipelineStage::DecodeEnd);
    CHECK(EosPipelineStage::OutputEnd != EosPipelineStage::Unknown);
}

static void test_eos_propagation_state() {
    using namespace kivo::pipeline::model::packet_flow;
    CHECK(EosPropagationState::NotStarted != EosPropagationState::Consumed);
}

static void test_eos_flow_policy() {
    using namespace kivo::pipeline::model::packet_flow;
    CHECK(EosFlowPolicy::StopAtEos != EosFlowPolicy::Ignore);
    CHECK(EosFlowPolicy::DrainThenStop != EosFlowPolicy::Unknown);
}

// --- discontinuity_flow tests ---
static void test_discontinuity_flow_action() {
    using namespace kivo::pipeline::model::packet_flow;
    CHECK(DiscontinuityFlowAction::FlushRequired != DiscontinuityFlowAction::ResumePossible);
    CHECK(DiscontinuityFlowAction::ReconfigureRequired != DiscontinuityFlowAction::DropRange);
}

static void test_discontinuity_flow_scope() {
    using namespace kivo::pipeline::model::packet_flow;
    CHECK(DiscontinuityFlowScope::SingleStream != DiscontinuityFlowScope::AllStreams);
}

static void test_discontinuity_flow_rule() {
    using namespace kivo::pipeline::model::packet_flow;
    DiscontinuityFlowRule rule;
    rule.type = kivo::pipeline::flow::discontinuity::DiscontinuityType::TimeJump;
    rule.action = DiscontinuityFlowAction::FlushRequired;
    rule.scope = DiscontinuityFlowScope::AllStreams;
    CHECK(rule.type == kivo::pipeline::flow::discontinuity::DiscontinuityType::TimeJump);
    CHECK(rule.action == DiscontinuityFlowAction::FlushRequired);
    CHECK(rule.scope == DiscontinuityFlowScope::AllStreams);
}

// --- sub-test runners ---
extern int run_lifecycle_control_flow_tests();
extern int run_pressure_generation_flow_tests();

int main() {
    // packet_sequence tests
    test_packet_sequence_order();
    test_sequence_validation_result();
    test_sequence_check_policy();
    test_packet_stream_position();

    // eos_flow tests
    test_eos_pipeline_stage();
    test_eos_propagation_state();
    test_eos_flow_policy();

    // discontinuity_flow tests
    test_discontinuity_flow_action();
    test_discontinuity_flow_scope();
    test_discontinuity_flow_rule();

    // sub-test runners
    run_lifecycle_control_flow_tests();
    run_pressure_generation_flow_tests();

    std::cout << "packet_flow_tests: " << g_passed_checks
              << " passed, " << g_failed_checks << " failed" << std::endl;
    return g_failed_checks > 0 ? 1 : 0;
}
