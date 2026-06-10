// Copyright (c) 2026 Kivo Project. All rights reserved.
// tests/core/presentation/presentation_policy_tests.cpp
#include "core/presentation/policy/presentation_pacing_policy.h"
#include "core/presentation/policy/eos_trickplay_policy.h"
#include "core/presentation/reschedule/presentation_reschedule_request.h"
#include <iostream>
extern int g_passed_checks;
extern int g_failed_checks;
#define CHECK(cond) do { if (!(cond)) { ++g_failed_checks; std::cerr << "FAILED: " << __FILE__ << ":" << __LINE__ << ": " << #cond << std::endl; } else { ++g_passed_checks; } } while(0)
static void test_pacing_policy() {
    using namespace kivo::playback::presentation;
    CHECK(PresentationPacingPolicy::ClockPaced != PresentationPacingPolicy::FreeRun);
}
static void test_eos_policy() {
    using namespace kivo::playback::presentation;
    CHECK(EosPresentationPolicy::DrainAllThenStop != EosPresentationPolicy::HoldLast);
}
static void test_trickplay_policy() {
    using namespace kivo::playback::presentation;
    CHECK(TrickplayPolicy::AnchorUnitsOnly != TrickplayPolicy::SparseUnits);
}
static void test_reschedule_request() {
    using namespace kivo::playback::presentation;
    PresentationRescheduleRequest req;
    req.reason = PresentationRescheduleReason::ClockCorrectionRequested;
    req.intent = PresentationRescheduleIntent::AdjustDeadline;
    CHECK(req.reason == PresentationRescheduleReason::ClockCorrectionRequested);
}
int run_presentation_policy_tests() {
    test_pacing_policy(); test_eos_policy(); test_trickplay_policy(); test_reschedule_request();
    return 0;
}
