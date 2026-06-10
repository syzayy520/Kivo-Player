// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/decoder/contracts/control/reconfigure.h - Decode reconfigure contract.
// Depends on: core/id, standard library.
// Does NOT depend on: real decode, pipeline.

#pragma once
#include "../../../core/id/playback_id.h"
#include <string>
#include <cstdint>

namespace kivo::decoder::contracts::control {

// ReconfigureMode - mode for reconfigure operation.
enum class ReconfigureMode {
    Unknown,
    HardReset,           // full decoder reset with new config
    InPlace,             // reconfigure without full reset (if supported)
    BestEffort,          // try in-place, fall back to hard reset
};

// DecodeReconfigureRequest - request to reconfigure a decoder.
struct DecodeReconfigureRequest {
    kivo::playback::GenerationId generation{};
    kivo::playback::TrackId track_id{};
    std::string new_codec_config_id{};
    ReconfigureMode mode{ReconfigureMode::BestEffort};
};

// DecodeReconfigureResult - result of a reconfigure operation.
enum class DecodeReconfigureResult {
    Unknown,
    Accepted,
    RejectedPendingDrain,
    RejectedIncompatible,
};

} // namespace kivo::decoder::contracts::control
