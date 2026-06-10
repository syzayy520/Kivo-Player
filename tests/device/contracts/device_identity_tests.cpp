#include "device/contracts/identity/device_id.h"
#include "device/contracts/identity/device_class.h"
#include "device/contracts/identity/device_identity.h"
#include <cassert>

int run_device_state_tests();
int run_device_event_tests();
int run_device_recovery_tests();
int run_device_policy_tests();

int main() {
    using namespace kivo::playback::device;
    DeviceId id{42};
    assert(id.value == 42);
    assert(DeviceClass::Graphics != DeviceClass::Audio);
    DeviceIdentity di{id, DeviceClass::Graphics};
    assert(di.device_class == DeviceClass::Graphics);
    assert(run_device_state_tests() == 0);
    assert(run_device_event_tests() == 0);
    assert(run_device_recovery_tests() == 0);
    assert(run_device_policy_tests() == 0);
    return 0;
}
