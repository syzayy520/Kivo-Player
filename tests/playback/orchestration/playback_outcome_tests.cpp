#include <cassert>
#include <iostream>
#include "playback/orchestration/outcome/playback_orchestration_status.h"
#include "playback/orchestration/outcome/playback_orchestration_outcome.h"
#include "playback/orchestration/outcome/playback_orchestration_failure_reason.h"
#include "playback/orchestration/outcome/playback_orchestration_drop_reason.h"

namespace kivo::playback::orchestration {
void run_playback_outcome_tests() {
    PlaybackOrchestrationStatus s1 = PlaybackOrchestrationStatus::Active;
    PlaybackOrchestrationStatus s2 = PlaybackOrchestrationStatus::Completed;
    PlaybackOrchestrationStatus s3 = PlaybackOrchestrationStatus::Failed;
    assert(s1 != s2); assert(s2 != s3);

    PlaybackOrchestrationOutcome outcome1;
    assert(outcome1.session_id.value == 0);
    assert(outcome1.status == PlaybackOrchestrationStatus::Unknown);
    PlaybackOrchestrationOutcome outcome2{.session_id{PlaybackSessionId{777}}, .status{PlaybackOrchestrationStatus::Completed}};
    assert(outcome2.session_id.value == 777);
    assert(outcome2.status == PlaybackOrchestrationStatus::Completed);

    PlaybackOrchestrationFailureReason f1 = PlaybackOrchestrationFailureReason::SessionInvalid;
    PlaybackOrchestrationFailureReason f2 = PlaybackOrchestrationFailureReason::BindingUnavailable;
    assert(f1 != f2);

    PlaybackOrchestrationDropReason d1 = PlaybackOrchestrationDropReason::Preempted;
    PlaybackOrchestrationDropReason d2 = PlaybackOrchestrationDropReason::SessionClosed;
    assert(d1 != d2);

    std::cout << "  playback_outcome_tests: ALL PASSED\n";
}
}
