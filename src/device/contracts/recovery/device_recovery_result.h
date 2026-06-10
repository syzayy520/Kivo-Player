#pragma once
#include "../identity/device_id.h"
#include "../state/device_generation.h"
#include "../policy/recovery_timeline_impact.h"
#include "device_recovery_status.h"
namespace kivo::playback::device { struct DeviceRecoveryResult { DeviceId device_id{}; DeviceRecoveryStatus status{DeviceRecoveryStatus::Unknown}; DeviceGeneration new_generation{}; RecoveryTimelineImpact timeline_impact{}; }; }
