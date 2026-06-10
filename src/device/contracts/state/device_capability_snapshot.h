#pragma once
#include "../../../capability/contracts/requirement/capability_result.h"
#include "../identity/device_id.h"
#include "device_generation.h"
namespace kivo::playback::device { struct DeviceCapabilitySnapshot { DeviceId device_id{}; DeviceGeneration generation{}; kivo::playback::capability::CapabilityResult result{}; }; }
