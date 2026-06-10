#include <cassert>
#include <iostream>
#include "audio/contracts/outcome/audio_render_outcome_status.h"
#include "audio/contracts/outcome/audio_render_outcome.h"
#include "audio/contracts/outcome/audio_render_failure_reason.h"
#include "audio/contracts/outcome/audio_render_drop_reason.h"

namespace kivo::playback::audio {
void run_audio_outcome_tests() {
    // Test AudioRenderOutcomeStatus
    AudioRenderOutcomeStatus stat1 = AudioRenderOutcomeStatus::Rendered;
    AudioRenderOutcomeStatus stat2 = AudioRenderOutcomeStatus::Dropped;
    AudioRenderOutcomeStatus stat3 = AudioRenderOutcomeStatus::Failed;
    AudioRenderOutcomeStatus stat4 = AudioRenderOutcomeStatus::Skipped;
    AudioRenderOutcomeStatus stat5 = AudioRenderOutcomeStatus::Unknown;
    assert(stat1 != stat2);
    assert(stat2 != stat3);
    assert(stat3 != stat4);
    assert(stat4 != stat5);

    // Test AudioRenderOutcome (typed ID + status only)
    AudioRenderOutcome outcome1;
    assert(outcome1.submission_id.value == 0);
    assert(outcome1.status == AudioRenderOutcomeStatus::Unknown);
    AudioRenderOutcome outcome2{
        .submission_id{AudioRenderSubmissionId{777888}},
        .status{AudioRenderOutcomeStatus::Rendered}
    };
    assert(outcome2.submission_id.value == 777888);
    assert(outcome2.status == AudioRenderOutcomeStatus::Rendered);

    // Test AudioRenderFailureReason
    AudioRenderFailureReason fail1 = AudioRenderFailureReason::EndpointUnavailable;
    AudioRenderFailureReason fail2 = AudioRenderFailureReason::FormatIncompatible;
    AudioRenderFailureReason fail3 = AudioRenderFailureReason::SubmissionTimedOut;
    AudioRenderFailureReason fail4 = AudioRenderFailureReason::ResourceExhaustion;
    AudioRenderFailureReason fail5 = AudioRenderFailureReason::Unknown;
    assert(fail1 != fail2);
    assert(fail2 != fail3);
    assert(fail3 != fail4);
    assert(fail4 != fail5);

    // Test AudioRenderDropReason
    AudioRenderDropReason drop1 = AudioRenderDropReason::LatePresentation;
    AudioRenderDropReason drop2 = AudioRenderDropReason::QueuePressure;
    AudioRenderDropReason drop3 = AudioRenderDropReason::GenerationStale;
    AudioRenderDropReason drop4 = AudioRenderDropReason::PolicyOverride;
    AudioRenderDropReason drop5 = AudioRenderDropReason::Unknown;
    assert(drop1 != drop2);
    assert(drop2 != drop3);
    assert(drop3 != drop4);
    assert(drop4 != drop5);

    std::cout << "  audio_outcome_tests: ALL PASSED\n";
}
}
