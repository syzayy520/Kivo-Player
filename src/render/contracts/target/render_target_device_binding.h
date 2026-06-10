#pragma once
#include "device/contracts/identity/device_id.h"
#include "render_target_id.h"
namespace kivo::playback::render {
struct RenderTargetDeviceBinding {
    RenderTargetId target_id{};
    kivo::playback::device::DeviceId device{};
};
}
