// Copyright (c) 2026 Kivo Project. All rights reserved.
// SPDX-License-Identifier: MIT
// src/demuxer/contracts/packet/packet_read_result.h - Packet read result contract.
// Depends on: demux_packet_descriptor.h, standard library.
// Does NOT depend on: platform, file IO, or network.

#pragma once
#include "demux_packet_descriptor.h"
#include <cstdint>

namespace kivo::playback::demuxer {

enum class PacketReadStatus {
    PacketAvailable,
    EndOfStream,
    Discontinuity,
    NeedSelection,
    SourceUnavailable,
    CorruptPacket,
};

enum class DemuxerError {
    None,
    SourceUnavailable,
    PacketCorrupt,
    StreamNotSelected,
    UnsupportedLayout,
};

enum class PacketDescriptorPresence {
    Present,
    Absent,
};

struct PacketReadResult {
    PacketReadStatus status{PacketReadStatus::SourceUnavailable};
    PacketDescriptorPresence packet_presence{PacketDescriptorPresence::Absent};
    DemuxPacketDescriptor packet{};
    DemuxerError error{DemuxerError::None};
};

}  // namespace kivo::playback::demuxer
