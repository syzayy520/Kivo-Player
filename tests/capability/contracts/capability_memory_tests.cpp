// Copyright (c) 2026 Kivo Project. All rights reserved.
#include "capability/contracts/memory/memory_capability.h"
#include <cassert>

int run_capability_memory_tests() {
    using namespace kivo::playback::capability;
    MemoryCapability mc{kivo::playback::memory::MemoryDomain::CpuLocal, {10, 1048576}, kivo::playback::memory::PoolPressure::Normal, CapabilityLevel::Full, CapabilityLevel::Full};
    assert(mc.domain == kivo::playback::memory::MemoryDomain::CpuLocal);
    assert(mc.budget.max_handles == 10);
    assert(mc.budget.max_bytes == 1048576);
    assert(mc.pressure == kivo::playback::memory::PoolPressure::Normal);
    assert(mc.allocation_level == CapabilityLevel::Full);
    assert(mc.sharing_level == CapabilityLevel::Full);
    return 0;
}
