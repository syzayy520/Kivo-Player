#pragma once
#include "core/clock/snapshot/system_clock_snapshot.h"
#include "core/clock/snapshot/device_reference_snapshot.h"
#include "core/clock/snapshot/presentation_reference_snapshot.h"
namespace kivo::playback::audio {
struct AudioClockSnapshot {
    kivo::playback::clock::SystemClockSnapshot system{};
    kivo::playback::clock::DeviceReferenceSnapshot device{};
    kivo::playback::clock::PresentationReferenceSnapshot presentation{};
};
}
