// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/pipeline/model/probe/codec_info_model.h - Codec info model.
// Depends on: standard library only.
// Does NOT depend on: decoder contracts, real decode.

#pragma once
#include <string>
#include <cstdint>

namespace kivo::pipeline::model::probe {

// CodecCategory - broad codec category.
enum class CodecCategory {
    Video,
    Audio,
    Subtitle,
    Data,
    Unknown,
};

// CodecLossiness - lossy/lossless classification.
enum class CodecLossiness {
    Lossy,
    Lossless,
    Unknown,
};

// CodecTraits - declared codec traits (bitmask, minimal set for P0-003).
enum class CodecTraits : uint32_t {
    Unknown          = 0,
    IntraOnly        = 1 << 0,
    VariableFramerate = 1 << 1,
    VariableBitrate  = 1 << 2,
};

// CodecInfoModel - codec information model.
struct CodecInfoModel {
    std::string codec_id{};
    std::string codec_name{};
    CodecCategory category{CodecCategory::Unknown};
    std::string codec_family{};
    std::string profile{};
    std::string level{};
    CodecLossiness lossiness{CodecLossiness::Unknown};
    uint32_t declared_traits{0};
};

} // namespace kivo::pipeline::model::probe
