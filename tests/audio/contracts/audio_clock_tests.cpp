#include <cassert>
#include <iostream>
#include "audio/contracts/clock/audio_clock_binding.h"
#include "audio/contracts/clock/audio_clock_snapshot.h"
#include "audio/contracts/clock/audio_drift_snapshot.h"

namespace kivo::playback::audio {
void run_audio_clock_tests() {
    // Test AudioClockBinding (consumes ClockDomain + AudioRendererId)
    AudioClockBinding binding1;
    assert(binding1.domain == kivo::playback::clock::ClockDomain::Unknown);
    assert(binding1.renderer_id.value == 0);
    AudioClockBinding binding2{
        .domain{kivo::playback::clock::ClockDomain::PresentationReference},
        .renderer_id{AudioRendererId{777}}
    };
    assert(binding2.domain == kivo::playback::clock::ClockDomain::PresentationReference);
    assert(binding2.renderer_id.value == 777);

    // Test AudioClockSnapshot (aggregates 3 P0-007 snapshots)
    AudioClockSnapshot snapshot1;
    assert(snapshot1.system.valid == false);
    assert(snapshot1.device.valid == false);
    assert(snapshot1.presentation.valid == false);
    AudioClockSnapshot snapshot2{
        .system{.monotonic_ticks{1000}, .tick_frequency{10000000}, .capture_generation{1}, .valid{true}},
        .device{.reference_position{500}, .reference_frequency{48000}, .source_generation{2}, .valid{true}},
        .presentation{.presentation_position{2000}, .presentation_interval_hint{33333}, .source_generation{3}, .valid{true}}
    };
    assert(snapshot2.system.monotonic_ticks == 1000);
    assert(snapshot2.device.reference_position == 500);
    assert(snapshot2.presentation.presentation_position == 2000);

    // Test AudioDriftSnapshot (consumes DriftObservation + AudioRendererId)
    AudioDriftSnapshot drift1;
    assert(drift1.observation.observed_at == 0);
    assert(drift1.observation.delta_us == 0);
    assert(drift1.renderer_id.value == 0);
    AudioDriftSnapshot drift2{
        .observation{.observed_at{5000}, .expected{kivo::playback::timeline::MediaTimestamp{{}, 1000}}, .actual{kivo::playback::timeline::MediaTimestamp{{}, 1100}}, .delta_us{100}},
        .renderer_id{AudioRendererId{888}}
    };
    assert(drift2.observation.delta_us == 100);
    assert(drift2.renderer_id.value == 888);

    std::cout << "  audio_clock_tests: ALL PASSED\n";
}
}
