// Copyright (c) 2026 Kivo Project. All rights reserved.
// tests/pipeline/model/probe/probe_model_tests.cpp - Media probe model tests.
// Lightweight self-check style (no Google Test).

#include "pipeline/model/probe/codec_info_model.h"
#include "pipeline/model/probe/stream_info_model.h"
#include "pipeline/model/probe/container_info_model.h"
#include "pipeline/model/probe/probe_result_model.h"
#include <iostream>

static int g_passed = 0;
static int g_failed = 0;

#define CHECK(cond) \
    do { \
        if (!(cond)) { \
            ++g_failed; \
            std::cerr << "FAILED: " << __FILE__ << ":" << __LINE__ << ": " << #cond << std::endl; \
        } else { \
            ++g_passed; \
        } \
    } while(0)

// --- codec_info_model tests ---
static void test_codec_info_defaults() {
    using namespace kivo::pipeline::model::probe;
    CodecInfoModel m;
    CHECK(m.codec_id.empty());
    CHECK(m.category == CodecCategory::Unknown);
    CHECK(m.lossiness == CodecLossiness::Unknown);
    CHECK(m.declared_traits == 0);
}

static void test_codec_info_populated() {
    using namespace kivo::pipeline::model::probe;
    CodecInfoModel m;
    m.codec_id = "h264";
    m.codec_name = "H.264";
    m.category = CodecCategory::Video;
    m.codec_family = "h264";
    m.profile = "High";
    m.level = "4.1";
    m.lossiness = CodecLossiness::Lossy;
    m.declared_traits = static_cast<uint32_t>(CodecTraits::VariableFramerate);
    CHECK(m.codec_id == "h264");
    CHECK(m.category == CodecCategory::Video);
    CHECK(m.lossiness == CodecLossiness::Lossy);
    CHECK(m.declared_traits & static_cast<uint32_t>(CodecTraits::VariableFramerate));
}

static void test_codec_traits_enum() {
    using namespace kivo::pipeline::model::probe;
    CHECK(static_cast<uint32_t>(CodecTraits::Unknown) == 0);
    CHECK(static_cast<uint32_t>(CodecTraits::IntraOnly) == 1);
    CHECK(static_cast<uint32_t>(CodecTraits::VariableFramerate) == 2);
    CHECK(static_cast<uint32_t>(CodecTraits::VariableBitrate) == 4);
}

// --- stream_info_model tests ---
static void test_stream_info_defaults() {
    using namespace kivo::pipeline::model::probe;
    StreamInfoModel m;
    CHECK(m.stream_index == 0);
    CHECK(m.stream_type == StreamType::Unknown);
    CHECK(m.timebase_num == 1);
    CHECK(m.timebase_den == 1);
    CHECK(m.video_width == 0);
    CHECK(m.video_height == 0);
    CHECK(m.audio_sample_rate == 0);
    CHECK(m.audio_channels == 0);
}

static void test_stream_info_video() {
    using namespace kivo::pipeline::model::probe;
    StreamInfoModel m;
    m.stream_index = 0;
    m.stream_type = StreamType::Video;
    m.video_width = 1920;
    m.video_height = 1080;
    m.pixel_format = "yuv420p";
    m.framerate_num = 24000;
    m.framerate_den = 1001;
    m.codec_info.codec_id = "h264";
    m.codec_info.category = CodecCategory::Video;
    CHECK(m.stream_type == StreamType::Video);
    CHECK(m.video_width == 1920);
    CHECK(m.video_height == 1080);
    CHECK(m.pixel_format == "yuv420p");
    CHECK(m.codec_info.codec_id == "h264");
}

static void test_stream_info_audio() {
    using namespace kivo::pipeline::model::probe;
    StreamInfoModel m;
    m.stream_index = 1;
    m.stream_type = StreamType::Audio;
    m.audio_sample_rate = 48000;
    m.audio_channels = 2;
    m.channel_layout = "stereo";
    m.codec_info.codec_id = "aac";
    m.codec_info.category = CodecCategory::Audio;
    CHECK(m.stream_type == StreamType::Audio);
    CHECK(m.audio_sample_rate == 48000);
    CHECK(m.audio_channels == 2);
    CHECK(m.channel_layout == "stereo");
    CHECK(m.codec_info.codec_id == "aac");
}

static void test_stream_disposition() {
    using namespace kivo::pipeline::model::probe;
    StreamInfoModel m;
    m.disposition = static_cast<uint32_t>(StreamDisposition::Default)
                  | static_cast<uint32_t>(StreamDisposition::Forced);
    CHECK(m.disposition & static_cast<uint32_t>(StreamDisposition::Default));
    CHECK(m.disposition & static_cast<uint32_t>(StreamDisposition::Forced));
    CHECK(!(m.disposition & static_cast<uint32_t>(StreamDisposition::HearingImpaired)));
}

// --- container_info_model tests ---
static void test_container_info_defaults() {
    using namespace kivo::pipeline::model::probe;
    ContainerInfoModel m;
    CHECK(m.format_name.empty());
    CHECK(!m.is_seekable);
    CHECK(m.stream_count == 0);
    CHECK(m.chapter_count == 0);
}

static void test_container_info_populated() {
    using namespace kivo::pipeline::model::probe;
    ContainerInfoModel m;
    m.format_name = "matroska";
    m.mime_type = "video/x-matroska";
    m.is_seekable = true;
    m.duration_ms = 60000;
    m.overall_bitrate = 5000000;
    m.stream_count = 3;
    m.chapter_count = 5;
    CHECK(m.format_name == "matroska");
    CHECK(m.is_seekable);
    CHECK(m.duration_ms == 60000);
    CHECK(m.stream_count == 3);
    CHECK(m.chapter_count == 5);
}

// --- probe_result_model tests ---
static void test_probe_result_defaults() {
    using namespace kivo::pipeline::model::probe;
    ProbeResultModel m;
    CHECK(m.streams.empty());
    CHECK(m.confidence == ProbeConfidence::Full);
    CHECK(m.source_hint.empty());
}

static void test_probe_result_populated() {
    using namespace kivo::pipeline::model::probe;
    ProbeResultModel m;
    m.container_info.format_name = "mp4";
    m.container_info.stream_count = 2;
    m.confidence = ProbeConfidence::Partial;
    m.probe_status = "truncated file";
    m.source_hint = "test.mp4";
    StreamInfoModel vid;
    vid.stream_index = 0;
    vid.stream_type = StreamType::Video;
    m.streams.push_back(vid);
    StreamInfoModel aud;
    aud.stream_index = 1;
    aud.stream_type = StreamType::Audio;
    m.streams.push_back(aud);
    CHECK(m.container_info.format_name == "mp4");
    CHECK(m.confidence == ProbeConfidence::Partial);
    CHECK(m.source_hint == "test.mp4");
    CHECK(m.streams.size() == 2);
    CHECK(m.streams[0].stream_type == StreamType::Video);
    CHECK(m.streams[1].stream_type == StreamType::Audio);
}

static void test_probe_result_not_god_model() {
    using namespace kivo::pipeline::model::probe;
    ProbeResultModel m;
    // ProbeResultModel is aggregation only - codec details live in StreamInfoModel.codec_info
    m.container_info.format_name = "mkv";
    m.streams.push_back(StreamInfoModel{});
    m.streams.back().codec_info.codec_id = "hevc";
    CHECK(m.streams[0].codec_info.codec_id == "hevc");
    // container info is NOT duplicated in ProbeResultModel
    CHECK(m.container_info.format_name == "mkv");
}

int main() {
    // codec_info_model tests
    test_codec_info_defaults();
    test_codec_info_populated();
    test_codec_traits_enum();

    // stream_info_model tests
    test_stream_info_defaults();
    test_stream_info_video();
    test_stream_info_audio();
    test_stream_disposition();

    // container_info_model tests
    test_container_info_defaults();
    test_container_info_populated();

    // probe_result_model tests
    test_probe_result_defaults();
    test_probe_result_populated();
    test_probe_result_not_god_model();

    std::cout << "probe_model_tests: " << g_passed << " passed, " << g_failed << " failed" << std::endl;
    return g_failed > 0 ? 1 : 0;
}
