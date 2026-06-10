// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/pipeline/contracts/probe/contract.h - Probe boundary contract.
// Depends on: pipeline_result.h, pipeline_error.h, core/id, standard library.
// Does NOT depend on: demuxer implementation, file IO.

#pragma once
#include "../pipeline_result.h"
#include "../pipeline_error.h"
#include "../../../core/id/playback_id.h"
#include <string>
#include <vector>

namespace kivo::pipeline::probe {

// ProbeRequest - request to probe a media source.
struct ProbeRequest {
    std::string source_url{};
    kivo::playback::SessionId session_id{};
};

// StreamProbeInfo - basic stream info from probe.
struct StreamProbeInfo {
    int stream_index{0};
    std::string codec_name{};
    std::string codec_type{}; // "audio", "video", "subtitle"
    int64_t bitrate{0};
    double duration_seconds{0.0};
};

// ProbeResult - result of media probing (NOT full P0-003 model).
struct ProbeResult {
    kivo::playback::SessionId session_id{};
    int64_t duration_ms{0};
    int64_t file_size_bytes{0};
    std::vector<StreamProbeInfo> streams{};
    std::string container_format{};
};

// probe_media - contract for probe operation (no implementation here).
// Returns PipelineResult<ProbeResult> or PipelineError.
struct ProbeContract {
    // This is a contract-only struct.
    // Actual implementation will be in P0-010 (future Probe Adapter).
};

} // namespace kivo::pipeline::probe
