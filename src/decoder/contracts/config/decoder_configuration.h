// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/decoder/contracts/config/decoder_configuration.h - Decoder configuration model.
// Depends on: standard library only.
// Does NOT depend on: real codec config, platform-specific types.

#pragma once
#include <string>
#include <cstdint>

namespace kivo::decoder::contracts::config {

// CodecConfigView - codec configuration view (contract only).
struct CodecConfigView {
    std::string codec_id{};
    int video_width{0};
    int video_height{0};
    int audio_sample_rate{0};
    int audio_channels{0};
    int64_t extradata_size_hint{0};
    std::string extradata_hint{};
};

} // namespace kivo::decoder::contracts::config
