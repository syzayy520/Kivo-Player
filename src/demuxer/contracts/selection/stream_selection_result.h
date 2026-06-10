// Copyright (c) 2026 Kivo Project. All rights reserved.
// SPDX-License-Identifier: MIT
// src/demuxer/contracts/selection/stream_selection_result.h - Stream selection result contract.
// Depends on: stream_selector.h, standard library.
// Does NOT depend on: platform, file IO, or network.

#pragma once
#include "stream_selector.h"
#include <cstdint>
#include <vector>

namespace kivo::playback::demuxer {

enum class StreamSelectionStatus {
    Selected,
    Deselected,
    AutoSelected,
    Unavailable,
    Unsupported,
};

struct SelectedStream {
    DemuxStreamId stream_id{};
    DemuxStreamKind kind{DemuxStreamKind::Unknown};
    DemuxProgramId program_id{};
    StreamSelectionStatus status{StreamSelectionStatus::Unavailable};
};

struct StreamSelectionResult {
    std::vector<SelectedStream> streams;
    uint32_t program_count{0};
    uint32_t attachment_count{0};
};

}  // namespace kivo::playback::demuxer
