// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/pipeline/model/packet_flow/lifecycle_flow.h - Flush/Drain/Seek lifecycle interaction flow.
// Depends on: pipeline/contracts/lifecycle/flush.h, drain.h, seek.h, standard library.
// Does NOT depend on: cancellation_flow.h, real demux, runtime engine.
// Does NOT define: CancellationScope (see cancellation_flow.h).

#pragma once
#include "../../contracts/lifecycle/flush.h"
#include "../../contracts/lifecycle/drain.h"
#include "../../contracts/lifecycle/seek.h"
#include <cstdint>

namespace kivo::pipeline::model::packet_flow {

// LifecycleCommandStatus - status of a lifecycle command.
enum class LifecycleCommandStatus {
    Unknown,
    Pending,
    Active,
    Completed,
    Aborted,
    Superseded,
};

// LifecycleStageMask - bitmask marking which pipeline stages a command has reached.
struct LifecycleStageMask {
    bool demux_stage{false};
    bool decode_stage{false};
    bool output_stage{false};
};

// FlushFlowMode - mode for flush operation.
enum class FlushFlowMode {
    Unknown,
    DiscardPending,      // discard all pending packets
    PreserveDrain,       // preserve packets during drain
    HardReset,           // hard reset, no preservation
};

// DrainFlowMode - mode for drain operation.
enum class DrainFlowMode {
    Unknown,
    BlockUntilEmpty,     // block until queue empty
    TimeoutWithRemainder, // timeout, may leave remainder
    Immediate,           // immediate, skip remainder
};

// SeekLifecycleRule - combined semantics for seek operation.
struct SeekLifecycleRule {
    bool eos_before{true};      // send EOS before flush
    bool flush_between{true};   // flush between EOS and new position
    bool eos_after{true};       // send EOS after seek completes
};

} // namespace kivo::pipeline::model::packet_flow
