#pragma once
#include "device_id.h"
#include "device_class.h"
namespace kivo::playback::device { struct DeviceIdentity { DeviceId id{}; DeviceClass device_class{DeviceClass::Unknown}; }; }
