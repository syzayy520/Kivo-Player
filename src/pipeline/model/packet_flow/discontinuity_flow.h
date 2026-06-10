// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/pipeline/model/packet_flow/discontinuity_flow.h - Discontinuity handling flow.
// Depends on: pipeline/contracts/flow/discontinuity.h, standard library.
// Does NOT depend on: real demux, real decode, real output.

#pragma once
#include "../../contracts/flow/discontinuity.h"
#include <cstdint>

namespace kivo::pipeline::model::packet_flow {

// DiscontinuityFlowAction - action to take on discontinuity.
enum class DiscontinuityFlowAction {
    Unknown,
    FlushRequired,          // pipeline must flush
    ReconfigureRequired,    // codec/stream reconfiguration needed
    ResumePossible,         // can resume without reconfigure
    DropRange,              // drop affected packets
};

// DiscontinuityFlowScope - scope of discontinuity impact.
enum class DiscontinuityFlowScope {
    Unknown,
    SingleStream,
    AllStreams,
    StreamGroup,
};

// DiscontinuityFlowResult - result of discontinuity handling.
enum class DiscontinuityFlowResult {
    Applied,
    Partial,
    Rejected,
};

// DiscontinuityFlowRule - maps discontinuity type to action.
struct DiscontinuityFlowRule {
    kivo::pipeline::flow::discontinuity::DiscontinuityType type{};
    DiscontinuityFlowAction action{DiscontinuityFlowAction::Unknown};
    DiscontinuityFlowScope scope{DiscontinuityFlowScope::Unknown};
};

} // namespace kivo::pipeline::model::packet_flow
