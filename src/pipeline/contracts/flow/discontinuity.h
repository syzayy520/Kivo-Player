// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/pipeline/contracts/flow/discontinuity.h - Discontinuity contract.
// Depends on: pipeline_result.h, pipeline_error.h, core/time, standard library.
// Does NOT depend on: real demuxer, decoder.

#pragma once
#include "../pipeline_result.h"
#include "../pipeline_error.h"
#include "../../../core/time/playback_time.h"
#include <cstdint>

namespace kivo::pipeline::flow::discontinuity {

// DiscontinuityType - type of discontinuity.
enum class DiscontinuityType {
    TimeJump,       // timestamp jump (pts/dts change)
    FormatChange,    // codec format change (resolution, sample rate)
    StreamSwitch,    // stream switch (adaptive streaming)
    Gap,             // gap in timeline (missing packets)
};

// DiscontinuityInfo - discontinuity information (contract only).
struct DiscontinuityInfo {
    DiscontinuityType type{DiscontinuityType::TimeJump};
    kivo::playback::MediaTime new_time{};
    kivo::playback::MediaTime old_time{};
    int64_t gap_ms{0};
};

// discontinuity_detected - contract for discontinuity detection (no implementation here).
// Returns PipelineResult<DiscontinuityInfo> or PipelineError.
struct DiscontinuityContract {
    // This is a contract-only struct.
    // Actual implementation will be in future tasks.
};

} // namespace kivo::pipeline::flow::discontinuity
