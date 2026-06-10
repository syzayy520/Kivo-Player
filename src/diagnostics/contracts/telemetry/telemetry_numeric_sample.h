#pragma once
#include "telemetry_sample_id.h"
#include "telemetry_sample_kind.h"
#include "telemetry_unit.h"
namespace kivo::playback::diagnostics {
struct TelemetryNumericSample {
    TelemetrySampleId sample_id{};
    TelemetrySampleKind kind{TelemetrySampleKind::Unknown};
    double value{0.0};
    TelemetryUnit unit{TelemetryUnit::Unknown};
};
}
