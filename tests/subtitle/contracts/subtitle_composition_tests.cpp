#include <cassert>
#include <iostream>
#include <vector>
#include "subtitle/contracts/composition/overlay_composition_id.h"
#include "subtitle/contracts/composition/overlay_composition_request.h"
#include "subtitle/contracts/composition/overlay_composition_result.h"
#include "subtitle/contracts/composition/overlay_composition_status.h"

namespace kivo::playback::subtitle {
void run_subtitle_composition_tests() {
    // Test OverlayCompositionId
    OverlayCompositionId id1;
    assert(id1.value == 0);
    OverlayCompositionId id2{999};
    assert(id2.value == 999);

    // Test OverlayCompositionRequest
    OverlayCompositionRequest req1;
    assert(req1.composition_id.value == 0);
    assert(req1.cue_ids.empty());
    assert(req1.target_plane_id.value == 0);
    assert(req1.presentation_timestamp.value == 0);
    assert(req1.deadline.deadline_us == 0);
    OverlayCompositionRequest req2{
        .composition_id{100},
        .cue_ids{SubtitleCueId{1}, SubtitleCueId{2}},
        .target_plane_id{50},
        .presentation_timestamp{kivo::playback::timeline::MediaTimestamp{{}, 33333}},
        .deadline{kivo::playback::presentation::PresentationDeadline{16666, 500}}
    };
    assert(req2.composition_id.value == 100);
    assert(req2.cue_ids.size() == 2);
    assert(req2.cue_ids[0].value == 1);
    assert(req2.target_plane_id.value == 50);
    assert(req2.presentation_timestamp.value == 33333);
    assert(req2.deadline.deadline_us == 16666);

    // Test OverlayCompositionResult
    OverlayCompositionResult result1;
    assert(result1.composition_id.value == 0);
    assert(result1.status == OverlayCompositionStatus::Unknown);
    assert(result1.cues_composed == 0);
    assert(result1.cues_dropped == 0);
    OverlayCompositionResult result2{
        .composition_id{200},
        .status{OverlayCompositionStatus::Composed},
        .cues_composed{5},
        .cues_dropped{0}
    };
    assert(result2.status == OverlayCompositionStatus::Composed);
    assert(result2.cues_composed == 5);

    // Test OverlayCompositionStatus
    OverlayCompositionStatus s1 = OverlayCompositionStatus::Composed;
    OverlayCompositionStatus s2 = OverlayCompositionStatus::Partial;
    OverlayCompositionStatus s3 = OverlayCompositionStatus::Failed;
    assert(s1 != s2);
    assert(s2 != s3);

    std::cout << "  subtitle_composition_tests: ALL PASSED\n";
}
}
