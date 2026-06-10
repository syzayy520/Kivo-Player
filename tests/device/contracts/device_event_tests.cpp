#include "device/contracts/event/device_change_event.h"
#include "device/contracts/event/device_loss_reason.h"
#include <cassert>

int run_device_event_tests() {
    using namespace kivo::playback::device;
    assert(DeviceChangeEvent::DeviceAdded != DeviceChangeEvent::DeviceLost);
    assert(DeviceLossReason::BackendInvalidated != DeviceLossReason::Timeout);
    assert(static_cast<int>(DeviceLossReason::Unknown) == 5);
    return 0;
}
