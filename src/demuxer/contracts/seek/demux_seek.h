// Copyright (c) 2026 Kivo Project. All rights reserved.
// SPDX-License-Identifier: MIT
// src/demuxer/contracts/seek/demux_seek.h - Demux seek contract.
// Depends on: core/timeline, standard library.
// Does NOT depend on: platform, file IO, or network.

#pragma once
#include "../../../core/timeline/timestamp/media_timestamp.h"
#include <cstdint>

namespace kivo::playback::demuxer {

enum class DemuxSeekMode {
    NearestAnchor,
    ExactTarget,
    FastApproximate,
};

struct DemuxSeekRequest {
    kivo::playback::timeline::MediaTimestamp target{{}, 0};
    DemuxSeekMode mode{DemuxSeekMode::NearestAnchor};
};

enum class DemuxSeekStatus {
    Positioned,
    Approximate,
    Unsupported,
    OutOfRange,
    Failed,
};

struct DemuxSeekResult {
    kivo::playback::timeline::MediaTimestamp actual_position{{}, 0};
    DemuxSeekStatus status{DemuxSeekStatus::Unsupported};
    bool exact{false};
};

}  // namespace kivo::playback::demuxer
