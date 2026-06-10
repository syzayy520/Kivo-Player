// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/pipeline/contracts/demux/contract.h - Demux boundary contract.
// Depends on: pipeline_result.h, pipeline_error.h, core/id, standard library.
// Does NOT depend on: real demuxer implementation.

#pragma once
#include "../pipeline_result.h"
#include "../pipeline_error.h"
#include "../../../core/id/playback_id.h"
#include <string>
#include <cstdint>

namespace kivo::pipeline::demux {

// DemuxRequest - request to initialize demuxer for a stream.
struct DemuxRequest {
    std::string source_url{};
    kivo::playback::SessionId session_id{};
    int stream_index{0};
};

// DemuxStatus - status of demuxer (contract only).
struct DemuxStatus {
    bool is_initialized{false};
    int64_t duration_ms{0};
    int stream_count{0};
    std::string codec_name{};
};

// DemuxPacketInfo - basic packet info from demuxer (contract only).
struct DemuxPacketInfo {
    int64_t pts_ms{0};
    int64_t dts_ms{0};
    int size_bytes{0};
    bool is_keyframe{false};
};

// demux_init - contract for demux initialization (no implementation here).
// Returns PipelineResult<DemuxStatus> or PipelineError.
struct DemuxInitContract {
    // This is a contract-only struct.
    // Actual implementation will be in P0-011 (future Demux Adapter).
};

// demux_read_packet - contract for reading one packet (no implementation here).
struct DemuxReadContract {
    // This is a contract-only struct.
    // Actual implementation will be in P0-011 (future Demux Adapter).
};

} // namespace kivo::pipeline::demux
