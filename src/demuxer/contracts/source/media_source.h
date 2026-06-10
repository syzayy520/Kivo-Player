// Copyright (c) 2026 Kivo Project. All rights reserved.
// SPDX-License-Identifier: MIT
// src/demuxer/contracts/source/media_source.h - Media source descriptor contract.
// Depends on: media_source_identity.h, standard library.
// Does NOT depend on: platform, file IO, or network.

#pragma once
#include "media_source_identity.h"
#include <cstdint>

namespace kivo::playback::demuxer {

struct MediaContainerHint {
    uint32_t family_id{0};
    uint32_t version{0};
};

struct MediaSource {
    MediaSourceIdentity identity{};
    int64_t duration_us{0};
    uint32_t stream_count{0};
    MediaContainerHint container_hint{};
};

}  // namespace kivo::playback::demuxer
