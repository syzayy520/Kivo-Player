// Copyright (c) 2026 Kivo Project. All rights reserved.
// SPDX-License-Identifier: MIT
// src/demuxer/contracts/packet/demux_packet_descriptor.h - Demux packet descriptor contract.
// Depends on: selection/stream_selector.h, core/timeline, standard library.
// Does NOT depend on: platform, file IO, or network.

#pragma once
#include "../selection/stream_selector.h"
#include "../../../core/timeline/timestamp/media_timestamp.h"
#include <cstdint>

namespace kivo::playback::demuxer {

enum class DemuxPacketKind {
    Media,
    Attachment,
    Chapter,
    Metadata,
    Discontinuity,
};

struct DemuxPacketDescriptor {
    uint64_t packet_id{0};
    DemuxStreamId stream_id{};
    kivo::playback::timeline::MediaTimestamp timestamp{{}, 0};
    DemuxPacketKind kind{DemuxPacketKind::Media};
    bool has_payload{false};
};

}  // namespace kivo::playback::demuxer
