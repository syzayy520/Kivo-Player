#include "device/contracts/policy/device_fallback_policy.h"
#include "device/contracts/policy/recovery_attempt_budget.h"
#include "device/contracts/policy/recovery_backoff_policy.h"
#include "device/contracts/policy/recovery_timeline_impact.h"
#include "device/contracts/policy/recovery_notification_policy.h"
#include <cassert>

int run_device_policy_tests() {
    using namespace kivo::playback::device;
    assert(DeviceFallbackPolicy::UseGeneralPurposePath != DeviceFallbackPolicy::Stop);
    RecoveryAttemptBudget b{5, 2};
    assert(b.max_attempts == 5);
    assert(b.attempts_made == 2);
    assert(RecoveryBackoffPolicy::Exponential != RecoveryBackoffPolicy::None);
    RecoveryTimelineImpact ti{RecoveryTimelineImpactKind::TimelineReset, kivo::playback::timeline::TimelineResetReason::Seek};
    assert(ti.kind == RecoveryTimelineImpactKind::TimelineReset);
    assert(RecoveryNotificationPolicy::NotifyOnFailure != RecoveryNotificationPolicy::Silent);
    return 0;
}
