#include <cassert>
#include <iostream>
#include "subtitle/contracts/outcome/subtitle_overlay_outcome_status.h"
#include "subtitle/contracts/outcome/subtitle_overlay_outcome.h"
#include "subtitle/contracts/outcome/subtitle_overlay_failure_reason.h"
#include "subtitle/contracts/outcome/subtitle_overlay_drop_reason.h"

namespace kivo::playback::subtitle {
void run_subtitle_outcome_tests() {
    // Test SubtitleOverlayOutcomeStatus
    SubtitleOverlayOutcomeStatus s1 = SubtitleOverlayOutcomeStatus::Presented;
    SubtitleOverlayOutcomeStatus s2 = SubtitleOverlayOutcomeStatus::Dropped;
    SubtitleOverlayOutcomeStatus s3 = SubtitleOverlayOutcomeStatus::Failed;
    SubtitleOverlayOutcomeStatus s4 = SubtitleOverlayOutcomeStatus::Skipped;
    assert(s1 != s2);
    assert(s2 != s3);
    assert(s3 != s4);

    // Test SubtitleOverlayOutcome
    SubtitleOverlayOutcome outcome1;
    assert(outcome1.composition_id.value == 0);
    assert(outcome1.status == SubtitleOverlayOutcomeStatus::Unknown);
    SubtitleOverlayOutcome outcome2{
        .composition_id{OverlayCompositionId{777}},
        .status{SubtitleOverlayOutcomeStatus::Presented}
    };
    assert(outcome2.composition_id.value == 777);
    assert(outcome2.status == SubtitleOverlayOutcomeStatus::Presented);

    // Test SubtitleOverlayFailureReason
    SubtitleOverlayFailureReason f1 = SubtitleOverlayFailureReason::PlaneUnavailable;
    SubtitleOverlayFailureReason f2 = SubtitleOverlayFailureReason::FormatIncompatible;
    SubtitleOverlayFailureReason f3 = SubtitleOverlayFailureReason::CueInvalid;
    SubtitleOverlayFailureReason f4 = SubtitleOverlayFailureReason::ResourceExhaustion;
    assert(f1 != f2);
    assert(f2 != f3);
    assert(f3 != f4);

    // Test SubtitleOverlayDropReason
    SubtitleOverlayDropReason d1 = SubtitleOverlayDropReason::LatePresentation;
    SubtitleOverlayDropReason d2 = SubtitleOverlayDropReason::PlaneOccupied;
    SubtitleOverlayDropReason d3 = SubtitleOverlayDropReason::GenerationStale;
    assert(d1 != d2);
    assert(d2 != d3);

    std::cout << "  subtitle_outcome_tests: ALL PASSED\n";
}
}
