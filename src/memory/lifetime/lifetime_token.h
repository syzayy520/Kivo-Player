// Copyright (c) 2026 Kivo Project. All rights reserved.
#pragma once
#include <cstdint>
namespace kivo::playback::memory {
struct LifetimeToken { uint64_t id{0}; uint32_t generation{0}; bool expired{false}; };
}
