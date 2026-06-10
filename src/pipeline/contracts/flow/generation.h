// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/pipeline/contracts/flow/generation.h - Generation contract (reuse core/id/GenerationId).
// Depends on: pipeline_result.h, pipeline_error.h, core/id, standard library.
// Does NOT depend on: real demuxer, decoder.

#pragma once
#include "../pipeline_result.h"
#include "../pipeline_error.h"
#include "../../../core/id/playback_id.h"
#include <cstdint>

namespace kivo::pipeline::flow::generation {

// GenerationToken - lightweight wrapper around core::GenerationId.
// Reuses core/id/GenerationId, does NOT create second generation system.
struct GenerationToken {
    kivo::playback::GenerationId id{};
    bool is_valid() const noexcept { return id.value != 0; }
};

// GenerationMismatch - error when generation mismatch detected.
struct GenerationMismatch {
    GenerationToken expected{};
    GenerationToken actual{};
};

// generation_check - contract for generation validation (no implementation here).
// Returns PipelineResult<void> or PipelineError.
struct GenerationCheckContract {
    // This is a contract-only struct.
    // Actual implementation will be in future tasks.
};

} // namespace kivo::pipeline::flow::generation
