// Copyright (c) 2026 Kivo Project. All rights reserved.
// SPDX-License-Identifier: MIT
// src/demuxer/contracts/source/media_source_identity.h - Media source identity contract.
// Depends on: standard library.
// Does NOT depend on: platform, file IO, or network.

#pragma once
#include <cstdint>
#include <string>

namespace kivo::playback::demuxer {

enum class MediaSourceLocatorKind {
    OpaqueHint,
    ExternalHandle,
    UserProvided,
    Unknown,
};

struct MediaSourceIdentity {
    uint64_t source_id{0};
    MediaSourceLocatorKind locator_kind{MediaSourceLocatorKind::Unknown};
    std::string source_hint;
};

}  // namespace kivo::playback::demuxer
