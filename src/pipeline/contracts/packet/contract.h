// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/pipeline/contracts/packet/contract.h - Packet boundary contract.
// Depends on: pipeline_result.h, pipeline_error.h, core/id, standard library.
// Does NOT depend on: real packet storage, queue implementation.

#pragma once
#include "../pipeline_result.h"
#include "../pipeline_error.h"
#include "../../../core/id/playback_id.h"
#include <cstdint>
#include <vector>

namespace kivo::pipeline::packet {

// PacketType - type of media packet.
enum class PacketType {
    Unknown,
    Video,
    Audio,
    Subtitle,
    Data,
};

// PacketFlags - flags for packet (keyframe, corruption, etc.).
struct PacketFlags {
    bool is_keyframe{false};
    bool is_corrupted{false};
    bool is_discontinuous{false};
};

// PacketInfo - basic packet information (contract only, no storage).
struct PacketInfo {
    int64_t pts_ms{0};
    int64_t dts_ms{0};
    int64_t duration_ms{0};
    int size_bytes{0};
    PacketType type{PacketType::Unknown};
    PacketFlags flags{};
    kivo::playback::TrackId track_id{};
};

// PacketBuffer - lightweight packet buffer reference (no ownership).
struct PacketBuffer {
    const uint8_t* data{nullptr};
    int64_t size_bytes{0};
};

// packet_read - contract for reading one packet (no implementation here).
// Returns PipelineResult<PacketInfo> or PipelineError.
struct PacketReadContract {
    // This is a contract-only struct.
    // Actual implementation will be in P0-011 (future Demux Adapter).
};

} // namespace kivo::pipeline::packet
