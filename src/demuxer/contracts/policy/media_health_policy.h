// Copyright (c) 2026 Kivo Project. All rights reserved.
// SPDX-License-Identifier: MIT
// src/demuxer/contracts/policy/media_health_policy.h - Media health policy contracts.
// Depends on: standard library.
// Does NOT depend on: platform, file IO, or network.

#pragma once

namespace kivo::playback::demuxer {

enum class DamagedMediaPolicy {
    FailFast,
    SkipDamagedUnits,
    BestEffort,
};

enum class TruncatedMediaPolicy {
    FailFast,
    ReadAvailable,
    UseAvailableIndex,
};

}  // namespace kivo::playback::demuxer
