// Copyright (c) 2026 Kivo Project. All rights reserved.
// SPDX-License-Identifier: MIT
#include "demuxer/contracts/seek/demux_seek.h"
#include <cassert>

using namespace kivo::playback::demuxer;

int run_demuxer_seek_tests() {
    // Default construct
    DemuxSeekRequest req{};
    assert(req.mode == DemuxSeekMode::NearestAnchor);

    DemuxSeekResult res{};
    assert(res.status == DemuxSeekStatus::Unsupported);
    assert(res.exact == false);

    // All modes
    req.mode = DemuxSeekMode::ExactTarget;
    assert(req.mode == DemuxSeekMode::ExactTarget);

    req.mode = DemuxSeekMode::FastApproximate;
    assert(req.mode == DemuxSeekMode::FastApproximate);

    // All statuses
    res.status = DemuxSeekStatus::Positioned;
    assert(res.status == DemuxSeekStatus::Positioned);

    res.status = DemuxSeekStatus::Approximate;
    assert(res.status == DemuxSeekStatus::Approximate);

    res.status = DemuxSeekStatus::OutOfRange;
    assert(res.status == DemuxSeekStatus::OutOfRange);

    res.status = DemuxSeekStatus::Failed;
    assert(res.status == DemuxSeekStatus::Failed);

    res.exact = true;
    assert(res.exact == true);

    return 0;
}
