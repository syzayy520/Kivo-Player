// Copyright (c) 2026 Kivo Project. All rights reserved.
// SPDX-License-Identifier: MIT
// src/demuxer/contracts/policy/stream_policy.h - Stream-level demux policies.
// Depends on: standard library.
// Does NOT depend on: platform, file IO, or network.

#pragma once

namespace kivo::playback::demuxer {

enum class SparseStreamPolicy {
    Include,
    Exclude,
    Conditional,
};

enum class AttachmentPolicy {
    Include,
    Exclude,
    ParseInlineOnly,
};

enum class ChapterPolicy {
    Skip,
    Forward,
    ParseAndExpose,
};

enum class MultiProgramPolicy {
    AutoSelectFirst,
    ManualSelect,
    ExposeAll,
};

}  // namespace kivo::playback::demuxer
