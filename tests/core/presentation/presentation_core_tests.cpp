// Copyright (c) 2026 Kivo Project. All rights reserved.
// tests/core/presentation/presentation_core_tests.cpp
#include "core/presentation/decision/presentation_decision.h"
#include "core/presentation/decision/presentation_verdict.h"
#include "core/presentation/timing/presentation_deadline.h"
#include "core/presentation/timing/presentation_lateness.h"
#include "core/presentation/fate/presentation_fate.h"
#include <iostream>
int g_passed_checks = 0;
int g_failed_checks = 0;
#define CHECK(cond) do { if (!(cond)) { ++g_failed_checks; std::cerr << "FAILED: " << __FILE__ << ":" << __LINE__ << ": " << #cond << std::endl; } else { ++g_passed_checks; } } while(0)

static void test_presentation_decision_enum() {
    using namespace kivo::playback::presentation;
    CHECK(PresentationDecision::Present != PresentationDecision::Drop);
    CHECK(PresentationDecision::Repeat != PresentationDecision::Hold);
}
static void test_presentation_verdict() {
    using namespace kivo::playback::presentation;
    CHECK(PresentationTimingVerdict::OnTime != PresentationTimingVerdict::TooLate);
    CHECK(PresentationReadiness::Ready != PresentationReadiness::Stale);
}
static void test_presentation_deadline() {
    using namespace kivo::playback::presentation;
    PresentationDeadline dl;
    dl.deadline_us = 16667;
    dl.tolerance_us = 500;
    CHECK(dl.deadline_us == 16667);
}
static void test_presentation_lateness() {
    using namespace kivo::playback::presentation;
    PresentationLateness lat;
    lat.delta_us = 3000;
    CHECK(lat.delta_us == 3000);
}
static void test_presentation_fate() {
    using namespace kivo::playback::presentation;
    CHECK(PresentationDropReason::TooLate != PresentationDropReason::Unknown);
    CHECK(PresentationRepeatReason::ReferenceHeld != PresentationRepeatReason::Unknown);
}
extern int run_presentation_queue_tests();
extern int run_presentation_policy_tests();
int main() {
    test_presentation_decision_enum();
    test_presentation_verdict();
    test_presentation_deadline();
    test_presentation_lateness();
    test_presentation_fate();
    run_presentation_queue_tests();
    run_presentation_policy_tests();
    std::cout << "presentation_tests: " << g_passed_checks << " passed, " << g_failed_checks << " failed" << std::endl;
    return g_failed_checks > 0 ? 1 : 0;
}
