// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/core/timeline/seek/preroll.h - Preroll policy contract.
// Does NOT depend on: pipeline, decoder, runtime.

#pragma once
#include <cstdint>

namespace kivo::playback::timeline {

// PrerollPolicy - policy for preroll before playback.
enum class PrerollPolicy {
    Unknown,
    None,
    KeyframeToTarget,
    FixedFrames,
    Adaptive,
};

// PrerollRequirements - requirements for preroll.
struct PrerollRequirements {
    int min_frames{0};
    int max_frames{0};
    bool keyframe_required{false};
};

} // namespace kivo::playback::timeline
