#pragma once
#include "../session/playback_session_id.h"
#include "device/contracts/identity/device_id.h"
namespace kivo::playback::orchestration {
struct PlaybackDeviceBinding {
    PlaybackSessionId session_id{};
    kivo::playback::device::DeviceId device_id{};
};
}
