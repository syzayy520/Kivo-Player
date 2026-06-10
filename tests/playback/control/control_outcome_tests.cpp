#include <cassert>
#include <iostream>
#include "playback/control/outcome/control_normalization_status.h"
#include "playback/control/outcome/control_normalization_outcome.h"
#include "playback/control/outcome/control_rejection_reason.h"
#include "playback/control/outcome/control_drop_reason.h"
namespace kivo::playback::control {
void run_control_outcome_tests() {
    ControlNormalizationStatus s1 = ControlNormalizationStatus::Accepted; ControlNormalizationStatus s2 = ControlNormalizationStatus::Rejected; ControlNormalizationStatus s3 = ControlNormalizationStatus::Dropped;
    assert(s1 != s2); assert(s2 != s3);
    ControlNormalizationOutcome out1;
    assert(out1.request_id.value == 0); assert(out1.status == ControlNormalizationStatus::Unknown);
    ControlNormalizationOutcome out2{.request_id{ControlRequestId{77}}, .status{ControlNormalizationStatus::Accepted}};
    assert(out2.status == ControlNormalizationStatus::Accepted);
    ControlRejectionReason r1 = ControlRejectionReason::CommandInvalid; ControlRejectionReason r2 = ControlRejectionReason::TargetInvalid; ControlRejectionReason r3 = ControlRejectionReason::SessionInvalid;
    assert(r1 != r2); assert(r2 != r3);
    ControlDropReason d1 = ControlDropReason::Superseded; ControlDropReason d2 = ControlDropReason::PriorityOverridden;
    assert(d1 != d2);
    std::cout << "  control_outcome_tests: ALL PASSED\n";
}
}
