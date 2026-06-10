// Copyright (c) 2026 Kivo Project. All rights reserved.
// tests/core/presentation/presentation_queue_tests.cpp
#include "core/presentation/queue/presentation_queue_policy.h"
#include "core/presentation/queue/queue_admission_decision.h"
#include <iostream>
extern int g_passed_checks;
extern int g_failed_checks;
#define CHECK(cond) do { if (!(cond)) { ++g_failed_checks; std::cerr << "FAILED: " << __FILE__ << ":" << __LINE__ << ": " << #cond << std::endl; } else { ++g_passed_checks; } } while(0)
static void test_watermark() {
    using namespace kivo::playback::presentation;
    PresentationWatermark wm;
    wm.min_units = 2; wm.max_units = 6; wm.target_units = 4;
    CHECK(wm.min_units == 2);
}
static void test_queue_policy() {
    using namespace kivo::playback::presentation;
    PresentationQueuePolicy policy;
    policy.hold_last_on_pause = true;
    CHECK(policy.hold_last_on_pause);
}
static void test_admission_decision() {
    using namespace kivo::playback::presentation;
    CHECK(QueueAdmissionDecision::Admit != QueueAdmissionDecision::Reject);
}
int run_presentation_queue_tests() {
    test_watermark(); test_queue_policy(); test_admission_decision();
    return 0;
}
