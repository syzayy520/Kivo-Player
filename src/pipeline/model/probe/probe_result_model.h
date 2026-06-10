// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/pipeline/model/probe/probe_result_model.h - Probe result model (aggregation).
// Depends on: container_info_model.h, stream_info_model.h, pipeline/contracts, standard library.
// Does NOT depend on: real probe, real demux.
// Does NOT: duplicate codec/container/stream fields (aggregation only).

#pragma once
#include "container_info_model.h"
#include "stream_info_model.h"
#include "../../contracts/pipeline_result.h"
#include <string>
#include <vector>

namespace kivo::pipeline::model::probe {

// ProbeConfidence - confidence level of probe result.
enum class ProbeConfidence {
    Full,       // complete media info available
    Partial,    // some streams/info missing
    Minimal,    // only basic container info
    Failed,     // probe failed
};

// ProbeResultModel - aggregated probe result (NOT a god model).
// Aggregates container info + stream list + confidence, does NOT duplicate sub-model fields.
struct ProbeResultModel {
    ContainerInfoModel container_info{};
    std::vector<StreamInfoModel> streams{};
    ProbeConfidence confidence{ProbeConfidence::Full};
    std::string probe_status{};
    std::string source_hint{};
};

} // namespace kivo::pipeline::model::probe
