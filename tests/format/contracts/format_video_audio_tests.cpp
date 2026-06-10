// Copyright (c) 2026 Kivo Project. All rights reserved.
#include "format/contracts/video/pixel_layout.h"
#include "format/contracts/video/chroma_subsampling.h"
#include "format/contracts/video/bit_depth_descriptor.h"
#include "format/contracts/video/pixel_format_descriptor.h"
#include "format/contracts/audio/sample_format_descriptor.h"
#include "format/contracts/audio/sample_rate_descriptor.h"
#include "format/contracts/audio/channel_layout_descriptor.h"
#include <cassert>

int run_format_video_audio_tests() {
    using namespace kivo::playback::format;
    assert(PixelLayout::Packed != PixelLayout::Planar);
    ChromaSubsampling cs{2, 1};
    assert(cs.horizontal == 2);
    BitDepthDescriptor bd{10, 10};
    assert(bd.luma_bits == 10);
    PixelFormatDescriptor pfd{1, bd, cs, PixelLayout::Planar, false};
    assert(pfd.format_family_id == 1);
    assert(!pfd.has_alpha);
    SampleFormatDescriptor sfd{1, 32, true, false};
    assert(sfd.is_float);
    SampleRateDescriptor srd{48000};
    assert(srd.rate_hz == 48000);
    ChannelLayoutDescriptor cld{0x3, 2};
    assert(cld.channel_count == 2);
    return 0;
}
