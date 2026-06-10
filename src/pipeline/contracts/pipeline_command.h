// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/pipeline/contracts/pipeline_command.h - Pipeline command model.
// Depends on: core/id, core/time, standard library.

#pragma once
#include "../../core/id/playback_id.h"
#include "../../core/time/playback_time.h"
#include <variant>

namespace kivo::pipeline {

// PipelineCmdOpen - request to open a media source for probing/demuxing.
struct PipelineCmdOpen {
    std::string source_url{};
};

// PipelineCmdReadPacket - request to read next packet from demuxer.
struct PipelineCmdReadPacket {};

// PipelineCmdFlush - request to flush pipeline (discard pending data).
struct PipelineCmdFlush {};

// PipelineCmdDrain - request to drain pipeline (process all pending data).
struct PipelineCmdDrain {};

// PipelineCmdSeek - request to seek to target position.
struct PipelineCmdSeek {
    kivo::playback::MediaTime target{};
    bool accurate{false};
};

// PipelineCmdCancel - request to cancel ongoing operation.
struct PipelineCmdCancel {
    kivo::playback::GenerationId generation{};
};

using PipelineCommand = std::variant<
    PipelineCmdOpen,
    PipelineCmdReadPacket,
    PipelineCmdFlush,
    PipelineCmdDrain,
    PipelineCmdSeek,
    PipelineCmdCancel
>;

} // namespace kivo::pipeline
