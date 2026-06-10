#include "device/contracts/recovery/device_recovery_policy.h"
#include "device/contracts/recovery/device_recovery_request.h"
#include "device/contracts/recovery/device_recovery_result.h"
#include "device/contracts/recovery/device_recovery_status.h"
#include "device/contracts/recovery/device_reopen_intent.h"
#include <cassert>

int run_device_recovery_tests() {
    using namespace kivo::playback::device;
    assert(DeviceRecoveryPolicy::AttemptRecovery != DeviceRecoveryPolicy::DeferToUser);
    assert(DeviceRecoveryStatus::Recovered != DeviceRecoveryStatus::Failed);
    assert(DeviceReopenIntent::SameIdentity != DeviceReopenIntent::DeferredSelection);
    DeviceRecoveryRequest req{DeviceId{1}, DeviceGeneration{1}, DeviceLossReason::ResourceUnavailable, DeviceRecoveryPolicy::AttemptRecovery};
    assert(req.device_id.value == 1);
    assert(req.reason == DeviceLossReason::ResourceUnavailable);
    DeviceRecoveryResult res{DeviceId{1}, DeviceRecoveryStatus::Recovered, DeviceGeneration{2}, RecoveryTimelineImpact{RecoveryTimelineImpactKind::TimelineContinued, kivo::playback::timeline::TimelineResetReason::Recovery}};
    assert(res.status == DeviceRecoveryStatus::Recovered);
    assert(res.new_generation.value == 2);
    assert(res.timeline_impact.kind == RecoveryTimelineImpactKind::TimelineContinued);
    return 0;
}
