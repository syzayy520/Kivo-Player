#pragma once
#include "device/contracts/identity/device_id.h"
#include "device/contracts/state/device_generation.h"
#include "render_target_id.h"
namespace kivo::playback::render {
struct RenderTargetDeviceBinding {
    RenderTargetId target_id{};
    kivo::playback::device::DeviceId device_id{};
    kivo::playback::device::DeviceGeneration device_generation{};
};
}
