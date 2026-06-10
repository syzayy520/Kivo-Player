// Copyright (c) 2026 Kivo Project. All rights reserved.
#pragma once
#include <cstdint>
#include "codec_family.h"
namespace kivo::playback::format {
struct CodecProfile { CodecFamily family{CodecFamily::Unknown}; uint32_t profile_idc{0}; uint32_t level_idc{0}; };
}
