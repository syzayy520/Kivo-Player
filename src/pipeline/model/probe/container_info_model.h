// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/pipeline/model/probe/container_info_model.h - Container info model.
// Depends on: standard library only.
// Does NOT depend on: real demux, real probe.
// Does NOT implement: full chapter model.

#pragma once
#include <string>
#include <cstdint>

namespace kivo::pipeline::model::probe {

// ContainerInfoModel - container/format information model.
struct ContainerInfoModel {
    std::string format_name{};
    std::string mime_type{};
    bool is_seekable{false};
    int64_t duration_ms{0};
    int64_t overall_bitrate{0};
    int stream_count{0};
    int chapter_count{0};
    std::string creation_time{};
};

} // namespace kivo::pipeline::model::probe
