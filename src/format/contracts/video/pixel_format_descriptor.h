// Copyright (c) 2026 Kivo Project. All rights reserved.
#pragma once
#include <cstdint>
#include "pixel_layout.h"
#include "chroma_subsampling.h"
#include "bit_depth_descriptor.h"
namespace kivo::playback::format {
struct PixelFormatDescriptor { uint32_t format_family_id{0}; BitDepthDescriptor bit_depth{}; ChromaSubsampling chroma_subsampling{}; PixelLayout layout{PixelLayout::Packed}; bool has_alpha{false}; };
}
