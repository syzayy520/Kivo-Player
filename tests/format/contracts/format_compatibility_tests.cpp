// Copyright (c) 2026 Kivo Project. All rights reserved.
#include "format/contracts/compatibility/media_format_compatibility.h"
#include "format/contracts/compatibility/format_truth_source.h"
#include <cassert>

int run_format_compatibility_tests() {
    using namespace kivo::playback::format;
    assert(MediaFormatCompatibility::Identical != MediaFormatCompatibility::Incompatible);
    assert(FormatTruthSource::ContainerDeclared != FormatTruthSource::DecoderReported);
    return 0;
}
