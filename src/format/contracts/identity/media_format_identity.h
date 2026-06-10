// Copyright (c) 2026 Kivo Project. All rights reserved.
#pragma once
#include <cstdint>
#include "codec_profile.h"
#include "media_stream_kind.h"
namespace kivo::playback::format {
struct MediaFormatIdentity { CodecProfile codec{}; uint32_t track_index{0}; MediaStreamKind stream_kind{MediaStreamKind::Unknown}; };
}
