#pragma once
#include "../../../memory/memory_domain.h"
#include "../../../memory/pool/pool_pressure.h"
#include "../../../memory/pool/pool_budget.h"
#include "../identity/device_id.h"
#include "device_generation.h"
namespace kivo::playback::device { struct DeviceMemorySnapshot { DeviceId device_id{}; DeviceGeneration generation{}; kivo::playback::memory::MemoryDomain domain{kivo::playback::memory::MemoryDomain::Unknown}; kivo::playback::memory::PoolPressure pressure{kivo::playback::memory::PoolPressure::Normal}; kivo::playback::memory::PoolBudget budget{}; }; }
