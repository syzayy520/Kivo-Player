// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/core/clock/observation/drift_observation.h - Drift observation contract.
// Depends on: core/timeline, standard library.
// Does NOT depend on: pipeline, runtime.

#pragma once
#include "../../timeline/timestamp/media_timestamp.h"
#include <cstdint>

namespace kivo::playback::clock {

// DriftObservation - observed drift between expected and actual position.
struct DriftObservation {
    int64_t observed_at{0};
    kivo::playback::timeline::MediaTimestamp expected{{}, 0};
    kivo::playback::timeline::MediaTimestamp actual{{}, 0};
    int64_t delta_us{0};
};

// DriftSeverity - severity of observed drift.
enum class DriftSeverity {
    None,
    Tolerable,
    Noticeable,
    Severe,
    Critical,
};

} // namespace kivo::playback::clock
