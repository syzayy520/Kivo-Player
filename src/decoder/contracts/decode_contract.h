// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/decoder/contracts/decode_contract.h - Decode input/output boundary.
// Depends on: core/id, standard library.
// Does NOT depend on: pipeline, real decode, hardware backends.

#pragma once
#include "../../core/id/playback_id.h"
#include <cstdint>
#include <string>

namespace kivo::decoder::contracts {

// EncodedPacketView - neutral view of an encoded packet for decode input.
// Does NOT include eos_flag (EOS belongs to flow/lifecycle contracts).
struct EncodedPacketView {
    kivo::playback::TrackId track_id{};
    int64_t pts{0};
    int64_t dts{0};
    int64_t duration{0};
    int64_t size_hint{0};
    bool is_keyframe{false};
    bool is_corrupted{false};
    bool has_discontinuity{false};
};

// DecodeCommandType - kind of decode command.
enum class DecodeCommandType {
    Unknown,
    DecodeInput,     // decode one input packet
    Flush,           // flush decoder
    Drain,           // drain decoder
    Reconfigure,     // reconfigure codec
};

} // namespace kivo::decoder::contracts
