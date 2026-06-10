// Copyright (c) 2026 Kivo Project. All rights reserved.
// tests/pipeline/contracts/stream_contract_tests.cpp - Stream contract tests.

#include "pipeline/contracts/stream/contract.h"
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

void test_stream_info() {
    kivo::pipeline::stream::StreamInfo info;
    info.track_id = kivo::playback::TrackId{1};
    info.type = kivo::pipeline::stream::StreamType::Video;
    info.codec_name = "h264";
    info.width = 1920;
    info.height = 1080;
    CHECK(info.track_id.value == 1);
    CHECK(info.type == kivo::pipeline::stream::StreamType::Video);
}

void test_stream_select_request() {
    kivo::pipeline::stream::StreamSelectRequest req;
    req.track_id = kivo::playback::TrackId{1};
    req.enable = true;
    CHECK(req.track_id.value == 1);
    CHECK(req.enable);
}
