// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/pipeline/model/packet_flow/packet_sequence.h - Packet serial & sequence flow.
// Depends on: core/id, standard library.
// Does NOT depend on: real demux, real decode, real output.

#pragma once
#include "../../../core/id/playback_id.h"
#include <cstdint>

namespace kivo::pipeline::model::packet_flow {

// PacketSequenceNumber - monotonically increasing packet sequence number.
using PacketSequenceNumber = uint64_t;

// SequenceOrder - ordering classification of received packets.
enum class SequenceOrder {
    Unknown,
    Sequential,     // expected order, no gap
    OutOfOrder,     // pts/dts reordering
    Gap,            // missing packets detected
};

// SequenceValidationResult - result of sequence order check.
enum class SequenceValidationResult {
    Valid,
    OutOfOrder,
    Duplicate,
    GapDetected,
};

// SequenceCheckPolicy - policy for sequence order validation.
enum class SequenceCheckPolicy {
    StrictForward,       // fail on any deviation
    AllowGapRecovery,    // tolerate gaps, recover
    BestEffort,          // log but continue
};

// PacketStreamPosition - position of a packet within a stream.
struct PacketStreamPosition {
    kivo::playback::TrackId track_id{};
    PacketSequenceNumber seq_number{0};
    int64_t pts{0};
    int64_t dts{0};
};

} // namespace kivo::pipeline::model::packet_flow
