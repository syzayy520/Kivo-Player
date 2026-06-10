// Copyright (c) 2026 Kivo Project. All rights reserved.
#pragma once
#include "mastering_display_metadata.h"
#include "content_light_metadata.h"
namespace kivo::playback::format {
struct HdrStaticMetadata { MasteringDisplayMetadata mastering{}; ContentLightMetadata content_light{}; };
}
