// Copyright (c) 2026 Kivo Project. All rights reserved.
#pragma once
#include <cstdint>
namespace kivo::playback::presentation {
struct PresentationDeadline { int64_t deadline_us{0}; int64_t tolerance_us{0}; };
}
