#include <cassert>
#include <iostream>
#include "subtitle/contracts/track/subtitle_track_id.h"
#include "subtitle/contracts/track/subtitle_track_role.h"
#include "subtitle/contracts/track/subtitle_track_identity.h"
#include "subtitle/contracts/track/subtitle_language_tag.h"

namespace kivo::playback::subtitle {
void run_subtitle_track_tests() {
    // Test SubtitleTrackId
    SubtitleTrackId id1;
    assert(id1.value == 0);
    SubtitleTrackId id2{42};
    assert(id2.value == 42);

    // Test SubtitleTrackRole
    SubtitleTrackRole r1 = SubtitleTrackRole::PrimarySubtitle;
    SubtitleTrackRole r2 = SubtitleTrackRole::SecondarySubtitle;
    SubtitleTrackRole r3 = SubtitleTrackRole::ForcedNarrative;
    SubtitleTrackRole r4 = SubtitleTrackRole::Commentary;
    SubtitleTrackRole r5 = SubtitleTrackRole::Unknown;
    assert(r1 != r2);
    assert(r2 != r3);
    assert(r3 != r4);
    assert(r4 != r5);

    // Test SubtitleTrackIdentity
    SubtitleTrackIdentity identity1;
    assert(identity1.id.value == 0);
    assert(identity1.role == SubtitleTrackRole::Unknown);
    SubtitleTrackIdentity identity2{.id{100}, .role{SubtitleTrackRole::PrimarySubtitle}};
    assert(identity2.id.value == 100);
    assert(identity2.role == SubtitleTrackRole::PrimarySubtitle);

    // Test SubtitleLanguageTag
    SubtitleLanguageTag tag1;
    assert(tag1.bcp47.empty());
    SubtitleLanguageTag tag2{"en-US"};
    assert(tag2.bcp47 == "en-US");

    std::cout << "  subtitle_track_tests: ALL PASSED\n";
}
void run_subtitle_cue_tests();
void run_subtitle_region_tests();
void run_subtitle_overlay_tests();
void run_subtitle_composition_tests();
void run_subtitle_outcome_tests();
}

int main() {
    using namespace kivo::playback::subtitle;
    run_subtitle_track_tests();
    run_subtitle_cue_tests();
    run_subtitle_region_tests();
    run_subtitle_overlay_tests();
    run_subtitle_composition_tests();
    run_subtitle_outcome_tests();
    std::cout << "  ALL subtitle contracts tests PASSED\n";
    return 0;
}
