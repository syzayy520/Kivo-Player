// Copyright (c) 2026 Kivo Project. All rights reserved.
#pragma once
#include "../../timeline/timestamp/media_timestamp.h"
namespace kivo::playback::presentation {
struct PresentationLateness { kivo::playback::timeline::MediaTimestamp expected{{},0}; kivo::playback::timeline::MediaTimestamp actual{{},0}; int64_t delta_us{0}; };
}
