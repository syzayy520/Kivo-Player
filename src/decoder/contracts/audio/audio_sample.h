// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/decoder/contracts/audio/audio_sample.h - Audio sample model.
// Depends on: core/time, standard library.
// Does NOT depend on: real data, hardware backends.

#pragma once
#include "../../../core/time/playback_time.h"
#include <cstdint>
#include <string>

namespace kivo::decoder::contracts::audio {

// AudioSampleFormat - audio sample format.
enum class AudioSampleFormat {
    Unknown,
    S16,
    S32,
    F32,
    S16Planar,
    F32Planar,
    U8,
    S64,
    F64,
};

// AudioChannelLayoutId - channel layout identifier.
enum class AudioChannelLayoutId {
    Unknown,
    Mono,
    Stereo,
    Surround_2_1,
    Surround_5_1,
    Surround_7_1,
};

// AudioSampleInfo - decoded audio sample information.
struct AudioSampleInfo {
    AudioSampleFormat format{AudioSampleFormat::Unknown};
    int sample_rate{0};
    int channels{0};
    AudioChannelLayoutId channel_layout_id{AudioChannelLayoutId::Unknown};
    int64_t sample_count{0};
    kivo::playback::MediaTime pts{0};
    int64_t duration_ms{0};
};

} // namespace kivo::decoder::contracts::audio
