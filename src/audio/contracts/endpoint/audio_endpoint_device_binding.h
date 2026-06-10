#pragma once
#include "audio_endpoint_id.h"
#include "device/contracts/identity/device_id.h"
#include "device/contracts/state/device_generation.h"
namespace kivo::playback::audio {
struct AudioEndpointDeviceBinding {
    AudioEndpointId endpoint_id{};
    kivo::playback::device::DeviceId device_id{};
    kivo::playback::device::DeviceGeneration device_generation{};
};
}
