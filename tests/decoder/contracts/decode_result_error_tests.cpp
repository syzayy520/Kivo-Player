// Copyright (c) 2026 Kivo Project. All rights reserved.
// tests/decoder/contracts/decode_result_error_tests.cpp

#include "decoder/contracts/decode_result.h"
#include "decoder/contracts/decode_error.h"
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

// --- decode_result tests ---
static void test_decode_output_kind() {
    using namespace kivo::decoder::contracts;
    CHECK(DecodeOutputKind::VideoFrame != DecodeOutputKind::AudioSample);
    CHECK(DecodeOutputKind::SubtitleSample != DecodeOutputKind::Empty);
}

static void test_decode_output_entry() {
    using namespace kivo::decoder::contracts;
    DecodeOutputEntry entry;
    entry.kind = DecodeOutputKind::VideoFrame;
    entry.track_id = kivo::playback::TrackId{0};
    entry.frame_index = 42;
    entry.pts = 1000;
    CHECK(entry.kind == DecodeOutputKind::VideoFrame);
    CHECK(entry.frame_index == 42);
    CHECK(entry.pts == 1000);
}

static void test_decode_result_status() {
    using namespace kivo::decoder::contracts;
    CHECK(DecodeResultStatus::Success != DecodeResultStatus::Error);
    CHECK(DecodeResultStatus::OutputAvailable != DecodeResultStatus::NeedMoreInput);
}

static void test_decode_result() {
    using namespace kivo::decoder::contracts;
    DecodeResult result;
    result.status = DecodeResultStatus::Success;
    result.entry.kind = DecodeOutputKind::AudioSample;
    CHECK(result.status == DecodeResultStatus::Success);
    CHECK(result.entry.kind == DecodeOutputKind::AudioSample);
    CHECK(result.error_message.empty());
}

// --- decode_error tests ---
static void test_decode_error_category() {
    using namespace kivo::decoder::contracts;
    CHECK(DecodeErrorCategory::InvalidInput != DecodeErrorCategory::Internal);
    CHECK(DecodeErrorCategory::UnsupportedCodec != DecodeErrorCategory::CorruptedData);
    // Verify no HardwareError exists
    CHECK(DecodeErrorCategory::ResourceUnavailable != DecodeErrorCategory::Timeout);
}

static void test_decode_error_info() {
    using namespace kivo::decoder::contracts;
    DecodeErrorInfo info;
    info.category = DecodeErrorCategory::CorruptedData;
    info.message = "bitstream error";
    info.input_index = 5;
    info.recoverable = false;
    CHECK(info.category == DecodeErrorCategory::CorruptedData);
    CHECK(info.message == "bitstream error");
    CHECK(!info.recoverable);
}

// --- sub-test runner ---
int run_decode_result_error_tests() {
    test_decode_output_kind();
    test_decode_output_entry();
    test_decode_result_status();
    test_decode_result();
    test_decode_error_category();
    test_decode_error_info();
    return 0;
}
