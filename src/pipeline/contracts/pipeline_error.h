// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/pipeline/contracts/pipeline_error.h - Pipeline error types.
// Depends on: standard library only.

#pragma once
#include <string>

namespace kivo::pipeline {

enum class PipelineErrorType {
    InvalidCommand,
    InvalidState,
    ProbeFailed,
    DemuxFailed,
    PacketQueueFull,
    FlushFailed,
    DrainFailed,
    SeekFailed,
    Cancelled,
    EndOfStream,
    Discontinuity,
    Backpressure,
    InternalError,
};

struct PipelineError {
    PipelineErrorType type{};
    std::string message{};

    PipelineError() = default;
    explicit PipelineError(PipelineErrorType t, std::string msg = {})
        : type(t), message(std::move(msg)) {}
};

} // namespace kivo::pipeline
