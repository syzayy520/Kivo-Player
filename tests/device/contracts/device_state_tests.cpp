#include "device/contracts/state/device_state.h"
#include "device/contracts/state/device_generation.h"
#include "device/contracts/state/device_capability_snapshot.h"
#include "device/contracts/state/device_memory_snapshot.h"
#include <cassert>

int run_device_state_tests() {
    using namespace kivo::playback::device;
    assert(DeviceState::Active != DeviceState::Lost);
    DeviceGeneration g{1};
    assert(g.value == 1);
    DeviceCapabilitySnapshot cs;
    cs.device_id = DeviceId{1};
    cs.generation = DeviceGeneration{1};
    assert(cs.device_id.value == 1);
    assert(cs.result.level == kivo::playback::capability::CapabilityLevel::Unknown);
    DeviceMemorySnapshot ms;
    ms.domain = kivo::playback::memory::MemoryDomain::CpuLocal;
    ms.pressure = kivo::playback::memory::PoolPressure::Normal;
    ms.budget = kivo::playback::memory::PoolBudget{8, 65536};
    assert(ms.domain == kivo::playback::memory::MemoryDomain::CpuLocal);
    assert(ms.budget.max_handles == 8);
    return 0;
}
