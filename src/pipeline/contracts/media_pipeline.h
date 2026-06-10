// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/pipeline/contracts/media_pipeline.h - Pipeline root handle and configuration.
// Depends on: pipeline_result.h, pipeline_error.h, pipeline_command.h, pipeline_event.h, core/id, standard library.

#pragma once
#include "pipeline_result.h"
#include "pipeline_error.h"
#include "pipeline_command.h"
#include "pipeline_event.h"
#include "../../core/id/playback_id.h"
#include <cstdint>
#include <functional>

namespace kivo::pipeline {

// PipelineHandle - opaque handle identifying one pipeline instance.
struct PipelineHandle {
    std::uint64_t value{0};
    constexpr auto operator==(PipelineHandle const&) const noexcept -> bool = default;
};

// PipelineConfig - configuration for pipeline creation.
struct PipelineConfig {
    std::int64_t queue_capacity_packets{1000};
    std::int64_t queue_capacity_bytes{50 * 1024 * 1024};
    bool enable_backpressure{true};
};

// PipelineEventCallback - callback type for pipeline events.
using PipelineEventCallback = std::function<void(PipelineEvent const&)>;

} // namespace kivo::pipeline
