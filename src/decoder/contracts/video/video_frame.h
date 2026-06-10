// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/decoder/contracts/video/video_frame.h - Video frame model.
// Depends on: core/time, standard library.
// Does NOT depend on: real data ptr, ownership, output surface.

#pragma once
#include "../../../core/time/playback_time.h"
#include <array>
#include <cstdint>

namespace kivo::decoder::contracts::video {

// VideoPixelFormat - pixel format enumeration.
enum class VideoPixelFormat {
    Unknown,
    YUV420P,
    NV12,
    RGB24,
    RGBA,
    YUV422P,
    YUV444P,
    P010LE,
};

// VideoPlaneLayout - layout of one video plane (no data pointer, no ownership).
struct VideoPlaneLayout {
    int plane_index{0};
    int stride_bytes{0};
    int row_count{0};
    int64_t byte_count_hint{0};
};

// VideoFrameInfo - decoded video frame information.
struct VideoFrameInfo {
    int width{0};
    int height{0};
    VideoPixelFormat pixel_format{VideoPixelFormat::Unknown};
    std::array<VideoPlaneLayout, 4> planes{};
    int plane_count{0};
    kivo::playback::MediaTime pts{0};
    int64_t duration_ms{0};
    bool is_keyframe{false};
};

} // namespace kivo::decoder::contracts::video
