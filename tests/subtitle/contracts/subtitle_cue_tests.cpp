#include <cassert>
#include <iostream>
#include "subtitle/contracts/cue/subtitle_cue_id.h"
#include "subtitle/contracts/cue/subtitle_cue_payload_kind.h"
#include "subtitle/contracts/cue/subtitle_cue_payload.h"
#include "subtitle/contracts/cue/subtitle_cue_timing.h"

namespace kivo::playback::subtitle {
void run_subtitle_cue_tests() {
    // Test SubtitleCueId
    SubtitleCueId id1;
    assert(id1.value == 0);
    SubtitleCueId id2{123};
    assert(id2.value == 123);

    // Test SubtitleCuePayloadKind (Text/Unknown only)
    SubtitleCuePayloadKind pk1 = SubtitleCuePayloadKind::Text;
    SubtitleCuePayloadKind pk2 = SubtitleCuePayloadKind::Unknown;
    assert(pk1 != pk2);

    // Test SubtitleCuePayload (text-only, no parser semantics)
    SubtitleCuePayload payload1;
    assert(payload1.cue_id.value == 0);
    assert(payload1.kind == SubtitleCuePayloadKind::Unknown);
    assert(payload1.text.empty());
    SubtitleCuePayload payload2{
        .cue_id{100},
        .kind{SubtitleCuePayloadKind::Text},
        .text{"Hello World"}
    };
    assert(payload2.cue_id.value == 100);
    assert(payload2.kind == SubtitleCuePayloadKind::Text);
    assert(payload2.text == "Hello World");

    // Test SubtitleCueTiming
    SubtitleCueTiming timing1;
    assert(timing1.cue_id.value == 0);
    assert(timing1.start.value == 0);
    assert(timing1.end.value == 0);
    SubtitleCueTiming timing2{
        .cue_id{200},
        .start{kivo::playback::timeline::MediaTimestamp{{}, 1000000}},
        .end{kivo::playback::timeline::MediaTimestamp{{}, 5000000}}
    };
    assert(timing2.cue_id.value == 200);
    assert(timing2.start.value == 1000000);
    assert(timing2.end.value == 5000000);

    std::cout << "  subtitle_cue_tests: ALL PASSED\n";
}
}
