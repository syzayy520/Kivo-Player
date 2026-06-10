// Copyright (c) 2026 Kivo Project. All rights reserved.
// SPDX-License-Identifier: MIT
// src/demuxer/contracts/selection/stream_selector.h - Stream selection request contract.
// Depends on: standard library.
// Does NOT depend on: platform, file IO, or network.

#pragma once
#include <cstdint>

namespace kivo::playback::demuxer {

struct DemuxStreamId {
    uint32_t value{0};
};

struct DemuxProgramId {
    uint32_t value{0};
    bool present{false};
};

enum class DemuxStreamKind {
    Unknown,
    Video,
    Audio,
    Subtitle,
    Attachment,
    Data,
};

enum class StreamSelectionIntent {
    Select,
    Deselect,
    Auto,
};

struct StreamSelector {
    DemuxStreamId stream_id{};
    DemuxStreamKind kind{DemuxStreamKind::Unknown};
    DemuxProgramId program_id{};
    StreamSelectionIntent intent{StreamSelectionIntent::Auto};
};

}  // namespace kivo::playback::demuxer
