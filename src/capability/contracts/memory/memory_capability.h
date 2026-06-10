#pragma once
#include "../../../memory/memory_domain.h"
#include "../../../memory/pool/pool_budget.h"
#include "../../../memory/pool/pool_pressure.h"
#include "../scope/capability_level.h"
namespace kivo::playback::capability {
struct MemoryCapability { kivo::playback::memory::MemoryDomain domain{kivo::playback::memory::MemoryDomain::Unknown}; kivo::playback::memory::PoolBudget budget{}; kivo::playback::memory::PoolPressure pressure{kivo::playback::memory::PoolPressure::Normal}; CapabilityLevel allocation_level{CapabilityLevel::Unknown}; CapabilityLevel sharing_level{CapabilityLevel::Unknown}; };
}
