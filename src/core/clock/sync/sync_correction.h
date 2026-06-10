// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/core/clock/sync/sync_correction.h - Sync correction contract.
// Depends on: standard library only.
// Does NOT depend on: pipeline, runtime
// Drop/Repeat/Display decisions belong to P0-008 Presentation.

#pragma once
#include <cstdint>

namespace kivo::playback::clock {

// SyncCorrectionMethod - method for correcting sync drift.
enum class SyncCorrectionMethod {
    Unknown,
    None,
    AdjustClockRate,
    AdjustClockAnchor,
    RequestPresentationReschedule,
    HoldProjection,
    HardResync,
};

// SyncCorrectionPolicy - policy for applying sync correction.
struct SyncCorrectionPolicy {
    SyncCorrectionMethod method{SyncCorrectionMethod::None};
    int64_t threshold_us{0};
    int max_correction_ppm{0};
    int max_consecutive{0};
};

} // namespace kivo::playback::clock
