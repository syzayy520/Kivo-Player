// Copyright (c) 2026 Kivo Project. All rights reserved.
// tests/pipeline/contracts/lifecycle_contract_tests.cpp - Lifecycle contract tests.

#include "pipeline/contracts/lifecycle/flush.h"
#include "pipeline/contracts/lifecycle/drain.h"
#include "pipeline/contracts/lifecycle/seek.h"
#include "pipeline/contracts/lifecycle/cancellation.h"
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

void test_flush_request() {
    kivo::pipeline::lifecycle::flush::FlushRequest req;
    req.generation = kivo::playback::GenerationId{1};
    req.discard_packets = true;
    CHECK(req.generation.value == 1);
    CHECK(req.discard_packets);
}

void test_drain_request() {
    kivo::pipeline::lifecycle::drain::DrainRequest req;
    req.generation = kivo::playback::GenerationId{2};
    req.wait_for_completion = false;
    CHECK(req.generation.value == 2);
    CHECK(!req.wait_for_completion);
}

void test_seek_request() {
    kivo::pipeline::lifecycle::seek::SeekRequest req;
    req.generation = kivo::playback::GenerationId{3};
    req.target = kivo::playback::MediaTime{5000};
    req.accurate = true;
    CHECK(req.generation.value == 3);
    CHECK(req.target == 5000);
}

void test_cancellation_token() {
    kivo::pipeline::lifecycle::cancellation::CancellationToken token;
    token.generation = kivo::playback::GenerationId{4};
    token.is_cancelled = false;
    CHECK(token.generation.value == 4);
    CHECK(!token.is_cancelled);
}
