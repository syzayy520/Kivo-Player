// Copyright (c) 2026 Kivo Project. All rights reserved.
// SPDX-License-Identifier: MIT
// src/demuxer/contracts/session/demuxer_session.h - Demuxer session contract.
// Depends on: core/id, standard library.
// Does NOT depend on: platform, file IO, or network.

#pragma once
#include "../../../core/id/playback_id.h"
#include <cstdint>

namespace kivo::playback::demuxer {

enum class DemuxerSessionState {
    Uninitialized,
    Probed,
    Active,
    Seeking,
    Ended,
    Failed,
};

struct DemuxerSession {
    kivo::playback::SessionId session_id{};
    uint64_t source_id{0};
    DemuxerSessionState state{DemuxerSessionState::Uninitialized};
};

}  // namespace kivo::playback::demuxer
