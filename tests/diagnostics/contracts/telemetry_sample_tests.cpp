#include <cassert>
#include <iostream>
#include "diagnostics/contracts/telemetry/telemetry_sample_id.h"
#include "diagnostics/contracts/telemetry/telemetry_sample_kind.h"
#include "diagnostics/contracts/telemetry/telemetry_numeric_sample.h"
#include "diagnostics/contracts/telemetry/telemetry_unit.h"

namespace kivo::playback::diagnostics {
void run_telemetry_sample_tests() {
    TelemetrySampleId sid1;
    assert(sid1.value == 0);
    TelemetrySampleId sid2{888};
    assert(sid2.value == 888);

    TelemetrySampleKind k1 = TelemetrySampleKind::Counter;
    TelemetrySampleKind k2 = TelemetrySampleKind::Gauge;
    TelemetrySampleKind k3 = TelemetrySampleKind::Duration;
    assert(k1 != k2); assert(k2 != k3);

    TelemetryUnit u1 = TelemetryUnit::Bytes;
    TelemetryUnit u2 = TelemetryUnit::Milliseconds;
    TelemetryUnit u3 = TelemetryUnit::Microseconds;
    TelemetryUnit u4 = TelemetryUnit::Frames;
    TelemetryUnit u5 = TelemetryUnit::Ratio;
    assert(u1 != u2); assert(u2 != u3); assert(u3 != u4); assert(u4 != u5);

    TelemetryNumericSample sample1;
    assert(sample1.sample_id.value == 0);
    assert(sample1.kind == TelemetrySampleKind::Unknown);
    assert(sample1.value == 0.0);
    assert(sample1.unit == TelemetryUnit::Unknown);
    TelemetryNumericSample sample2{.sample_id{100}, .kind{TelemetrySampleKind::Counter}, .value{42.0}, .unit{TelemetryUnit::Frames}};
    assert(sample2.sample_id.value == 100);
    assert(sample2.kind == TelemetrySampleKind::Counter);
    assert(sample2.value == 42.0);
    assert(sample2.unit == TelemetryUnit::Frames);

    std::cout << "  telemetry_sample_tests: ALL PASSED\n";
}
}
