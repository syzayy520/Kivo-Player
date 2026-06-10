// Copyright (c) 2026 Kivo Project. All rights reserved.
// tests/pipeline/contracts/demux_contract_tests.cpp - Demux contract tests.

#include "pipeline/contracts/demux/contract.h"
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

void test_demux_request() {
    kivo::pipeline::demux::DemuxRequest req;
    req.source_url = "test.mp4";
    req.session_id = kivo::playback::SessionId{1};
    req.stream_index = 0;
    CHECK(req.source_url == "test.mp4");
    CHECK(req.session_id.value == 1);
}

void test_demux_status() {
    kivo::pipeline::demux::DemuxStatus status;
    status.is_initialized = true;
    status.duration_ms = 60000;
    status.stream_count = 2;
    CHECK(status.is_initialized);
    CHECK(status.duration_ms == 60000);
}
