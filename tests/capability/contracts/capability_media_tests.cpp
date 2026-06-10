// Copyright (c) 2026 Kivo Project. All rights reserved.
#include "capability/contracts/media/codec_capability.h"
#include "capability/contracts/media/codec_capability_set.h"
#include "capability/contracts/media/pixel_format_capability.h"
#include "capability/contracts/media/sample_format_capability.h"
#include "capability/contracts/media/color_space_capability.h"
#include "capability/contracts/media/hdr_metadata_capability.h"
#include "capability/contracts/media/format_capability_set.h"
#include <cassert>

int run_capability_media_tests() {
    using namespace kivo::playback::capability;
    CodecCapability cc{kivo::playback::format::CodecFamily::H264, CapabilityLevel::Full, 100, 41, 1920, 1080, 60};
    assert(cc.family == kivo::playback::format::CodecFamily::H264);
    assert(cc.level == CapabilityLevel::Full);
    CodecCapabilitySet ccs;
    ccs.entries.push_back(cc);
    assert(ccs.entries.size() == 1);
    PixelFormatCapability pfc{1, CapabilityLevel::Full, false};
    assert(!pfc.supports_interlaced);
    SampleFormatCapability sfc{1, CapabilityLevel::Full};
    assert(sfc.level == CapabilityLevel::Full);
    ColorSpaceCapability csc;
    csc.primaries.push_back(kivo::playback::format::ColorPrimaries::BT2020);
    csc.transfers.push_back(kivo::playback::format::TransferCharacteristics::SMPTE2084);
    csc.matrices.push_back(kivo::playback::format::MatrixCoefficients::BT2020_NCL);
    csc.ranges.push_back(kivo::playback::format::ColorRange::Limited);
    csc.level = CapabilityLevel::Full;
    assert(csc.primaries.size() == 1);
    assert(csc.matrices.size() == 1);
    assert(csc.ranges.size() == 1);
    HdrMetadataCapability hmc;
    hmc.static_metadata_readable = true;
    assert(hmc.static_metadata_readable);
    FormatCapabilitySet fcs;
    fcs.pixels.push_back(pfc);
    fcs.samples.push_back(sfc);
    fcs.color_spaces.push_back(csc);
    fcs.hdr = hmc;
    assert(fcs.pixels.size() == 1);
    assert(fcs.samples.size() == 1);
    return 0;
}
