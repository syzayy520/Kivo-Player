// Copyright (c) 2026 Kivo Project. All rights reserved.
// tests/core/clock/clock_sync_tests.cpp
// Tests: sync/sync_correction.h, observation/drift_observation.h

#include "core/clock/sync/sync_correction.h"
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

static void test_sync_correction_method() {
    using namespace kivo::playback::clock;
    CHECK(SyncCorrectionMethod::None != SyncCorrectionMethod::HardResync);
    CHECK(SyncCorrectionMethod::AdjustClockRate != SyncCorrectionMethod::HoldProjection);
    CHECK(SyncCorrectionMethod::RequestPresentationReschedule != SyncCorrectionMethod::Unknown);
}

static void test_sync_correction_policy() {
    using namespace kivo::playback::clock;
    SyncCorrectionPolicy policy;
    policy.method = SyncCorrectionMethod::AdjustClockRate;
    policy.threshold_us = 10000;
    policy.max_correction_ppm = 500;
    policy.max_consecutive = 3;
    CHECK(policy.method == SyncCorrectionMethod::AdjustClockRate);
    CHECK(policy.threshold_us == 10000);
    CHECK(policy.max_consecutive == 3);
}

int run_clock_sync_tests() {
    test_sync_correction_method();
    test_sync_correction_policy();
    return 0;
}
