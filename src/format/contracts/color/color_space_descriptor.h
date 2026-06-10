// Copyright (c) 2026 Kivo Project. All rights reserved.
#pragma once
#include "color_primaries.h"
#include "transfer_characteristics.h"
#include "matrix_coefficients.h"
#include "color_range.h"
namespace kivo::playback::format {
struct ColorSpaceDescriptor { ColorPrimaries primaries{ColorPrimaries::Unknown}; TransferCharacteristics transfer{TransferCharacteristics::Unknown}; MatrixCoefficients matrix{MatrixCoefficients::Unknown}; ColorRange range{ColorRange::Unknown}; };
}
