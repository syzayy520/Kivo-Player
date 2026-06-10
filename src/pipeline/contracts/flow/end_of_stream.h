// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/pipeline/contracts/flow/end_of_stream.h - End of Stream contract.
// Depends on: pipeline_result.h, pipeline_error.h, core/id, standard library.
// Does NOT depend on: real demuxer, decoder.

#pragma once
#include "../pipeline_result.h"
#include "../pipeline_error.h"
#include "../../../core/id/playback_id.h"
#include <cstdint>

namespace kivo::pipeline::flow::end_of_stream {

// EndOfStreamSignal - signal that end of stream reached.
struct EndOfStreamSignal {
    kivo::playback::SessionId session_id{};
    int64_t stream_index{0};
    int64_t last_pts_ms{0};
};

// end_of_stream_detected - contract for EOS detection (no implementation here).
// Returns PipelineResult<EndOfStreamSignal> or PipelineError.
struct EndOfStreamContract {
    // This is a contract-only struct.
    // Actual implementation will be in future tasks.
};

} // namespace kivo::pipeline::flow::end_of_stream
