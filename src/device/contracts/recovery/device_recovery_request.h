#pragma once
#include "../identity/device_id.h"
#include "../state/device_generation.h"
#include "../event/device_loss_reason.h"
#include "device_recovery_policy.h"
namespace kivo::playback::device { struct DeviceRecoveryRequest { DeviceId device_id{}; DeviceGeneration generation{}; DeviceLossReason reason{DeviceLossReason::Unknown}; DeviceRecoveryPolicy policy{DeviceRecoveryPolicy::Unknown}; }; }
