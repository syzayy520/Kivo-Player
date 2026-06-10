// Copyright (c) 2026 Kivo Project. All rights reserved.
#pragma once
namespace kivo::playback::format {
enum class CodecFamily {
    Unknown,
    H264, H265, H266, AV1, VP9,
    MPEG2Video, MPEG4Video,
    AAC, MP3, FLAC, Opus, Vorbis,
    AC3, EAC3, DTS, TrueHD,
    Subrip, WebVTT, ASS, PGS, DVBSub,
};
}
