#pragma once
#include <vector>
#include "../../../format/contracts/color/color_primaries.h"
#include "../../../format/contracts/color/transfer_characteristics.h"
#include "../../../format/contracts/color/matrix_coefficients.h"
#include "../../../format/contracts/color/color_range.h"
#include "../scope/capability_level.h"
namespace kivo::playback::capability {
struct ColorSpaceCapability {
    std::vector<kivo::playback::format::ColorPrimaries> primaries;
    std::vector<kivo::playback::format::TransferCharacteristics> transfers;
    std::vector<kivo::playback::format::MatrixCoefficients> matrices;
    std::vector<kivo::playback::format::ColorRange> ranges;
    CapabilityLevel level{CapabilityLevel::Unknown};
};
}
