// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/pipeline/model/probe/stream_info_model.h - Stream info model.
// Depends on: codec_info_model.h, core/id, standard library.
// Does NOT depend on: decoder contracts, real demux.

#pragma once
#include "codec_info_model.h"
#include "../../../core/id/playback_id.h"
#include <string>
#include <cstdint>

namespace kivo::pipeline::model::probe {

// StreamType - type of media stream.
enum class StreamType {
    Video,
    Audio,
    Subtitle,
    Data,
    Unknown,
};

// SubtitleKind - subtitle format kind.
enum class SubtitleKind {
    Text,
    Bitmap,
    Unknown,
};

// StreamDisposition - stream disposition flags (bitmask).
enum class StreamDisposition : uint32_t {
    None            = 0,
    Default         = 1 << 0,
    Forced          = 1 << 1,
    HearingImpaired = 1 << 2,
    VisualImpaired  = 1 << 3,
};

// StreamInfoModel - stream-level media information model.
struct StreamInfoModel {
    int stream_index{0};
    StreamType stream_type{StreamType::Unknown};
    std::string language{};
    uint32_t disposition{0};
    int64_t duration_ms{0};
    int timebase_num{1};
    int timebase_den{1};

    // video fields
    int video_width{0};
    int video_height{0};
    std::string pixel_format{};
    int sar_num{1};
    int sar_den{1};
    int framerate_num{0};
    int framerate_den{1};

    // audio fields
    int audio_sample_rate{0};
    int audio_channels{0};
    std::string channel_layout{};

    // subtitle fields
    SubtitleKind subtitle_kind{SubtitleKind::Unknown};

    // embedded codec info
    CodecInfoModel codec_info{};
};

} // namespace kivo::pipeline::model::probe
