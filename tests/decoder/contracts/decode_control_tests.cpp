// Copyright (c) 2026 Kivo Project. All rights reserved.
// tests/decoder/contracts/decode_control_tests.cpp
// Tests: decode_contract.h, decode_status.h, config, control/flush/drain/reconfigure

#include "decoder/contracts/decode_contract.h"
#include "decoder/contracts/decode_status.h"
#include "decoder/contracts/config/decoder_configuration.h"
#include "decoder/contracts/control/flush.h"
#include "decoder/contracts/control/drain.h"
#include "decoder/contracts/control/reconfigure.h"
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

// --- decode_contract tests ---
static void test_encoded_packet_view() {
    using namespace kivo::decoder::contracts;
    EncodedPacketView pkt;
    pkt.track_id = kivo::playback::TrackId{0};
    pkt.pts = 1000;
    pkt.is_keyframe = true;
    pkt.has_discontinuity = false;
    CHECK(pkt.track_id.value == 0);
    CHECK(pkt.pts == 1000);
    CHECK(pkt.is_keyframe);
    CHECK(!pkt.has_discontinuity);
}

static void test_encoded_packet_no_eos() {
    // EncodedPacketView must NOT contain eos_flag
    using namespace kivo::decoder::contracts;
    EncodedPacketView pkt;
    CHECK(!pkt.is_corrupted);
    CHECK(!pkt.has_discontinuity);
}

static void test_decode_command_type() {
    using namespace kivo::decoder::contracts;
    CHECK(DecodeCommandType::DecodeInput != DecodeCommandType::Flush);
    CHECK(DecodeCommandType::Drain != DecodeCommandType::Reconfigure);
}

// --- decode_status tests ---
static void test_decoder_stage() {
    using namespace kivo::decoder::contracts;
    CHECK(DecoderStage::Idle != DecoderStage::Active);
    CHECK(DecoderStage::Flushing != DecoderStage::Draining);
    CHECK(DecoderStage::Stopped != DecoderStage::Error);
}

static void test_decode_progress() {
    using namespace kivo::decoder::contracts;
    DecodeProgress progress;
    progress.inputs_consumed = 100;
    progress.outputs_produced = 95;
    progress.errors_encountered = 2;
    CHECK(progress.inputs_consumed == 100);
    CHECK(progress.outputs_produced == 95);
}

// --- config tests ---
static void test_codec_config_view() {
    using namespace kivo::decoder::contracts::config;
    CodecConfigView cfg;
    cfg.codec_id = "h264";
    cfg.video_width = 1920;
    cfg.video_height = 1080;
    cfg.audio_sample_rate = 0;
    cfg.audio_channels = 0;
    CHECK(cfg.codec_id == "h264");
    CHECK(cfg.video_width == 1920);
    CHECK(cfg.video_height == 1080);
}

// --- control/flush tests ---
static void test_flush_strategy() {
    using namespace kivo::decoder::contracts::control;
    CHECK(FlushStrategy::DiscardAll != FlushStrategy::SoftReset);
}

static void test_flush_request() {
    using namespace kivo::decoder::contracts::control;
    DecodeFlushRequest req;
    req.generation = kivo::playback::GenerationId{1};
    req.track_id = kivo::playback::TrackId{0};
    req.strategy = FlushStrategy::ProduceRemaining;
    CHECK(req.generation.value == 1);
    CHECK(req.strategy == FlushStrategy::ProduceRemaining);
}

// --- control/drain tests ---
static void test_drain_mode() {
    using namespace kivo::decoder::contracts::control;
    CHECK(DrainMode::BlockUntilEmpty != DrainMode::Immediate);
}

static void test_drain_request() {
    using namespace kivo::decoder::contracts::control;
    DecodeDrainRequest req;
    req.generation = kivo::playback::GenerationId{2};
    req.mode = DrainMode::TimeoutMs;
    req.timeout_ms = 500;
    CHECK(req.generation.value == 2);
    CHECK(req.mode == DrainMode::TimeoutMs);
    CHECK(req.timeout_ms == 500);
}

// --- control/reconfigure tests ---
static void test_reconfigure_mode() {
    using namespace kivo::decoder::contracts::control;
    CHECK(ReconfigureMode::HardReset != ReconfigureMode::BestEffort);
}

static void test_reconfigure_request() {
    using namespace kivo::decoder::contracts::control;
    DecodeReconfigureRequest req;
    req.generation = kivo::playback::GenerationId{3};
    req.track_id = kivo::playback::TrackId{1};
    req.new_codec_config_id = "hevc_main";
    req.mode = ReconfigureMode::InPlace;
    CHECK(req.generation.value == 3);
    CHECK(req.mode == ReconfigureMode::InPlace);
    CHECK(req.new_codec_config_id == "hevc_main");
}

// --- sub-test runner ---
int run_decode_control_tests() {
    test_encoded_packet_view();
    test_encoded_packet_no_eos();
    test_decode_command_type();
    test_decoder_stage();
    test_decode_progress();
    test_codec_config_view();
    test_flush_strategy();
    test_flush_request();
    test_drain_mode();
    test_drain_request();
    test_reconfigure_mode();
    test_reconfigure_request();
    return 0;
}
