// Copyright (c) 2026 Kivo Project. All rights reserved.
#include "format/contracts/color/color_primaries.h"
#include "format/contracts/color/transfer_characteristics.h"
#include "format/contracts/color/matrix_coefficients.h"
#include "format/contracts/color/color_range.h"
#include "format/contracts/color/color_space_descriptor.h"
#include <cassert>

int run_format_color_tests() {
    using namespace kivo::playback::format;
    assert(ColorPrimaries::BT709 != ColorPrimaries::BT2020);
    assert(TransferCharacteristics::SMPTE2084 != TransferCharacteristics::BT709);
    assert(MatrixCoefficients::BT2020_NCL != MatrixCoefficients::Identity);
    assert(ColorRange::Limited != ColorRange::Full);
    ColorSpaceDescriptor csd{ColorPrimaries::BT2020, TransferCharacteristics::SMPTE2084, MatrixCoefficients::BT2020_NCL, ColorRange::Limited};
    assert(csd.primaries == ColorPrimaries::BT2020);
    assert(csd.transfer == TransferCharacteristics::SMPTE2084);
    assert(csd.range == ColorRange::Limited);
    return 0;
}
