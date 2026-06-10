// Copyright (c) 2026 Kivo Project. All rights reserved.
// tests/core/clock/clock_domain_tests.cpp
// Contains: main(), CHECK macro, global counters

#include "core/clock/clock_domains/clock_domain.h"
#include "core/clock/clock_domains/master_clock.h"
#include "core/clock/clock_domains/media_clock.h"
#include "core/clock/snapshot/system_clock_snapshot.h"
#include "core/clock/snapshot/device_reference_snapshot.h"
#include "core/clock/snapshot/presentation_reference_snapshot.h"
#include "core/clock/observation/clock_projection.h"
#include "core/clock/observation/clock_health.h"
#include "core/clock/observation/drift_observation.h"
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

// --- domain tests ---
static void test_clock_domain_enum() {
    using namespace kivo::playback::clock;
    CHECK(ClockDomain::SystemMonotonic != ClockDomain::DeviceReference);
    CHECK(ClockDomain::PresentationReference != ClockDomain::Unknown);
}

static void test_master_clock() {
    using namespace kivo::playback::clock;
    MasterClock mc;
    mc.domain = ClockDomain::SystemMonotonic;
    mc.resolution_hz = 1000000;
    mc.timeline_ref_id = 0;
    CHECK(mc.domain == ClockDomain::SystemMonotonic);
    CHECK(mc.resolution_hz == 1000000);
}

static void test_media_clock() {
    using namespace kivo::playback::clock;
    MediaClock mc;
    mc.domain = ClockDomain::PresentationReference;
    mc.rate = 1.0;
    CHECK(mc.domain == ClockDomain::PresentationReference);
    CHECK(mc.rate == 1.0);
}

// --- snapshot tests ---
static void test_system_clock_snapshot() {
    using namespace kivo::playback::clock;
    SystemClockSnapshot snap;
    snap.monotonic_ticks = 1000000;
    snap.tick_frequency = 1000000;
    snap.valid = true;
    CHECK(snap.monotonic_ticks == 1000000);
    CHECK(snap.valid);
}

static void test_device_reference_snapshot() {
    using namespace kivo::playback::clock;
    DeviceReferenceSnapshot snap;
    snap.reference_position = 48000;
    snap.reference_frequency = 48000;
    snap.valid = true;
    CHECK(snap.reference_position == 48000);
    CHECK(snap.valid);
}

static void test_presentation_reference_snapshot() {
    using namespace kivo::playback::clock;
    PresentationReferenceSnapshot snap;
    snap.presentation_position = 60;
    snap.presentation_interval_hint = 16667;
    snap.valid = true;
    CHECK(snap.presentation_position == 60);
    CHECK(snap.valid);
}

// --- observation tests ---
static void test_clock_projection() {
    using namespace kivo::playback::clock;
    ClockProjection proj;
    proj.confidence = ProjectionConfidence::Exact;
    CHECK(proj.confidence == ProjectionConfidence::Exact);
    CHECK(ProjectionConfidence::Drifting != ProjectionConfidence::Invalid);
}

static void test_clock_health() {
    using namespace kivo::playback::clock;
    CHECK(ClockHealth::Healthy != ClockHealth::Lost);
    CHECK(ClockFallbackPolicy::UseSystemReference != ClockFallbackPolicy::MarkProjectionInvalid);
}

static void test_drift_observation() {
    using namespace kivo::playback::clock;
    DriftObservation obs;
    obs.delta_us = 5000;
    CHECK(obs.delta_us == 5000);
    CHECK(DriftSeverity::None != DriftSeverity::Critical);
}

extern int run_clock_sync_tests();
extern int run_clock_control_tests();

int main() {
    test_clock_domain_enum();
    test_master_clock();
    test_media_clock();
    test_system_clock_snapshot();
    test_device_reference_snapshot();
    test_presentation_reference_snapshot();
    test_clock_projection();
    test_clock_health();
    test_drift_observation();

    run_clock_sync_tests();
    run_clock_control_tests();

    std::cout << "clock_tests: " << g_passed_checks << " passed, " << g_failed_checks << " failed" << std::endl;
    return g_failed_checks > 0 ? 1 : 0;
}
