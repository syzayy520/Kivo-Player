#pragma once
#include <vector>
#include "pixel_format_capability.h"
#include "sample_format_capability.h"
#include "color_space_capability.h"
#include "hdr_metadata_capability.h"
namespace kivo::playback::capability {
struct FormatCapabilitySet { std::vector<PixelFormatCapability> pixels; std::vector<SampleFormatCapability> samples; std::vector<ColorSpaceCapability> color_spaces; HdrMetadataCapability hdr{}; };
}
