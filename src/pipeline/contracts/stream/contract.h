// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/pipeline/contracts/stream/contract.h - Stream boundary contract.
// Depends on: pipeline_result.h, pipeline_error.h, core/id, standard library.
// Does NOT depend on: real decoder implementation.

#pragma once
#include "../pipeline_result.h"
#include "../pipeline_error.h"
#include "../../../core/id/playback_id.h"
#include <string>
#include <cstdint>

namespace kivo::pipeline::stream {

// StreamType - type of media stream.
enum class StreamType {
    Unknown,
    Video,
    Audio,
    Subtitle,
    Data,
};

// StreamInfo - basic stream information (contract only).
struct StreamInfo {
    kivo::playback::TrackId track_id{};
    StreamType type{StreamType::Unknown};
    std::string codec_name{};
    int64_t bitrate_bps{0};
    int sample_rate{0};      // for audio
    int channels{0};         // for audio
    int width{0};            // for video
    int height{0};           // for video
    double fps{0.0};       // for video
};

// StreamSelectRequest - request to select a stream for decoding.
struct StreamSelectRequest {
    kivo::playback::TrackId track_id{};
    bool enable{true};
};

// stream_info_query - contract for querying stream info (no implementation here).
// Returns PipelineResult<std::vector<StreamInfo>> or PipelineError.
struct StreamInfoQueryContract {
    // This is a contract-only struct.
    // Actual implementation will be in P0-011 (future Demux Adapter).
};

} // namespace kivo::pipeline::stream
