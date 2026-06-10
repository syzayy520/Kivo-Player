// Copyright (c) 2026 Kivo Project. All rights reserved.
#pragma once
#include <cstdint>
namespace kivo::playback::memory {
struct PoolBudget { int max_handles{0}; int64_t max_bytes{0}; };
}
