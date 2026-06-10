// Copyright (c) 2026 Kivo Project. All rights reserved.
// tests/pipeline/contracts/probe_contract_tests.cpp - Probe contract tests.

#include "pipeline/contracts/probe/contract.h"
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

void test_probe_request() {
    kivo::pipeline::probe::ProbeRequest req;
    req.source_url = "test.mp4";
    req.session_id = kivo::playback::SessionId{1};
    CHECK(req.source_url == "test.mp4");
    CHECK(req.session_id.value == 1);
}

void test_probe_result() {
    kivo::pipeline::probe::ProbeResult res;
    res.session_id = kivo::playback::SessionId{1};
    res.duration_ms = 60000;
    res.file_size_bytes = 1024 * 1024;
    CHECK(res.session_id.value == 1);
    CHECK(res.duration_ms == 60000);
}
