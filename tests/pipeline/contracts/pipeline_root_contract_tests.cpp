// Copyright (c) 2026 Kivo Project. All rights reserved.
// tests/pipeline/contracts/pipeline_root_contract_tests.cpp - Root test driver.

#include "pipeline/contracts/pipeline_result.h"
#include "pipeline/contracts/pipeline_error.h"
#include "pipeline/contracts/pipeline_command.h"
#include "pipeline/contracts/pipeline_event.h"
#include "pipeline/contracts/media_pipeline.h"
#include <iostream>
#include <cassert>

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

// Root test functions
static void test_pipeline_error_type() {
    kivo::pipeline::PipelineError err(kivo::pipeline::PipelineErrorType::ProbeFailed, "probe failed");
    CHECK(err.type == kivo::pipeline::PipelineErrorType::ProbeFailed);
    CHECK(!err.message.empty());
}

static void test_pipeline_result_ok() {
    int value = 42;
    auto r = kivo::pipeline::PipelineResult<int>::ok(value);
    CHECK(r.is_ok());
    CHECK(!r.is_err());
    CHECK(r.unwrap() == 42);
}

static void test_pipeline_result_err() {
    kivo::pipeline::PipelineError err(kivo::pipeline::PipelineErrorType::DemuxFailed, "demux failed");
    auto r = kivo::pipeline::PipelineResult<int>::err(err);
    CHECK(!r.is_ok());
    CHECK(r.is_err());
    CHECK(r.error().type == kivo::pipeline::PipelineErrorType::DemuxFailed);
}

static void test_pipeline_command_variant() {
    kivo::pipeline::PipelineCommand cmd = kivo::pipeline::PipelineCmdOpen{"test.mp4"};
    CHECK(std::holds_alternative<kivo::pipeline::PipelineCmdOpen>(cmd));
}

static void test_pipeline_event_variant() {
    kivo::pipeline::PipelineEvent ev = kivo::pipeline::PipelineEvProbeCompleted{kivo::playback::SessionId{1}};
    CHECK(std::holds_alternative<kivo::pipeline::PipelineEvProbeCompleted>(ev));
}

static void test_pipeline_handle() {
    kivo::pipeline::PipelineHandle h{42};
    CHECK(h.value == 42);
    CHECK(h == kivo::pipeline::PipelineHandle{42});
    CHECK(!(h == kivo::pipeline::PipelineHandle{0}));
}

// Sub-file test function declarations
extern void test_probe_request();
extern void test_probe_result();
extern void test_demux_request();
extern void test_demux_status();
extern void test_stream_info();
extern void test_stream_select_request();
extern void test_packet_info();
extern void test_packet_buffer();
extern void test_queue_config();
extern void test_queue_status();
extern void test_flush_request();
extern void test_drain_request();
extern void test_seek_request();
extern void test_cancellation_token();
extern void test_discontinuity_info();
extern void test_end_of_stream_signal();
extern void test_backpressure_signal();
extern void test_backpressure_level_canonical();
extern void test_generation_token();

int main() {
    // pipeline_root tests
    test_pipeline_error_type();
    test_pipeline_result_ok();
    test_pipeline_result_err();
    test_pipeline_command_variant();
    test_pipeline_event_variant();
    test_pipeline_handle();

    // probe tests
    test_probe_request();
    test_probe_result();

    // demux tests
    test_demux_request();
    test_demux_status();

    // stream tests
    test_stream_info();
    test_stream_select_request();

    // packet tests
    test_packet_info();
    test_packet_buffer();

    // queue tests
    test_queue_config();
    test_queue_status();

    // lifecycle tests
    test_flush_request();
    test_drain_request();
    test_seek_request();
    test_cancellation_token();

    // flow tests
    test_discontinuity_info();
    test_end_of_stream_signal();
    test_backpressure_signal();
    test_backpressure_level_canonical();
    test_generation_token();

    std::cout << "kivo_pipeline_contract_tests: " << g_passed_checks << " passed checks, " << g_failed_checks << " failed checks" << std::endl;
    return g_failed_checks > 0 ? 1 : 0;
}
