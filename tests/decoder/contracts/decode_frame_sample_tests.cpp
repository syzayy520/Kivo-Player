// Copyright (c) 2026 Kivo Project. All rights reserved.
// tests/decoder/contracts/decode_frame_sample_tests.cpp
// Tests: video_frame.h, audio_sample.h, subtitle_sample.h
// Contains: main(), CHECK macro, global counters

#include "decoder/contracts/video/video_frame.h"
#include "decoder/contracts/audio/audio_sample.h"
#include "decoder/contracts/subtitle/subtitle_sample.h"
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

// --- video_frame tests ---
static void test_video_pixel_format() {
    using namespace kivo::decoder::contracts::video;
    CHECK(VideoPixelFormat::YUV420P != VideoPixelFormat::NV12);
    CHECK(VideoPixelFormat::RGBA != VideoPixelFormat::Unknown);
}

static void test_video_plane_layout() {
    using namespace kivo::decoder::contracts::video;
    VideoPlaneLayout plane;
    plane.plane_index = 0;
    plane.stride_bytes = 1920;
    plane.row_count = 1080;
    plane.byte_count_hint = 1920 * 1080;
    CHECK(plane.plane_index == 0);
    CHECK(plane.stride_bytes == 1920);
    CHECK(plane.row_count == 1080);
}

static void test_video_frame_info() {
    using namespace kivo::decoder::contracts::video;
    VideoFrameInfo frame;
    frame.width = 1920;
    frame.height = 1080;
    frame.pixel_format = VideoPixelFormat::YUV420P;
    frame.plane_count = 3;
    frame.planes[0].stride_bytes = 1920;
    frame.planes[0].row_count = 1080;
    frame.planes[1].stride_bytes = 960;
    frame.planes[1].row_count = 540;
    frame.planes[2].stride_bytes = 960;
    frame.planes[2].row_count = 540;
    frame.pts = kivo::playback::MediaTime{1000};
    frame.duration_ms = 40;
    frame.is_keyframe = true;
    CHECK(frame.width == 1920);
    CHECK(frame.height == 1080);
    CHECK(frame.pixel_format == VideoPixelFormat::YUV420P);
    CHECK(frame.plane_count == 3);
    CHECK(frame.pts == 1000);
    CHECK(frame.is_keyframe);
}

// --- audio_sample tests ---
static void test_audio_sample_format() {
    using namespace kivo::decoder::contracts::audio;
    CHECK(AudioSampleFormat::S16 != AudioSampleFormat::F32);
    CHECK(AudioSampleFormat::S16Planar != AudioSampleFormat::Unknown);
}

static void test_audio_channel_layout() {
    using namespace kivo::decoder::contracts::audio;
    CHECK(AudioChannelLayoutId::Mono != AudioChannelLayoutId::Surround_7_1);
}

static void test_audio_sample_info() {
    using namespace kivo::decoder::contracts::audio;
    AudioSampleInfo info;
    info.format = AudioSampleFormat::S16;
    info.sample_rate = 48000;
    info.channels = 2;
    info.channel_layout_id = AudioChannelLayoutId::Stereo;
    info.sample_count = 1024;
    info.pts = kivo::playback::MediaTime{2000};
    info.duration_ms = 21;
    CHECK(info.format == AudioSampleFormat::S16);
    CHECK(info.sample_rate == 48000);
    CHECK(info.channels == 2);
    CHECK(info.channel_layout_id == AudioChannelLayoutId::Stereo);
    CHECK(info.sample_count == 1024);
}

// --- subtitle_sample tests ---
static void test_subtitle_sample_kind() {
    using namespace kivo::decoder::contracts::subtitle;
    CHECK(SubtitleSampleKind::Text != SubtitleSampleKind::Bitmap);
}

static void test_subtitle_timing() {
    using namespace kivo::decoder::contracts::subtitle;
    SubtitleTimingInfo timing;
    timing.start_pts = kivo::playback::MediaTime{1000};
    timing.end_pts = kivo::playback::MediaTime{5000};
    CHECK(timing.start_pts == 1000);
    CHECK(timing.end_pts == 5000);
}

static void test_subtitle_decoded_sample() {
    using namespace kivo::decoder::contracts::subtitle;
    SubtitleDecodedSample sample;
    sample.kind = SubtitleSampleKind::Text;
    sample.payload_kind = "utf8";
    sample.text_hint = "Hello";
    sample.timing.start_pts = kivo::playback::MediaTime{0};
    sample.timing.end_pts = kivo::playback::MediaTime{3000};
    CHECK(sample.kind == SubtitleSampleKind::Text);
    CHECK(sample.text_hint == "Hello");
    // Verify no style model leakage
}

// --- sub-test runners ---
extern int run_decode_control_tests();
extern int run_decode_result_error_tests();

int main() {
    test_video_pixel_format();
    test_video_plane_layout();
    test_video_frame_info();
    test_audio_sample_format();
    test_audio_channel_layout();
    test_audio_sample_info();
    test_subtitle_sample_kind();
    test_subtitle_timing();
    test_subtitle_decoded_sample();

    run_decode_control_tests();
    run_decode_result_error_tests();

    std::cout << "decoder_contract_tests: " << g_passed_checks
              << " passed, " << g_failed_checks << " failed" << std::endl;
    return g_failed_checks > 0 ? 1 : 0;
}
