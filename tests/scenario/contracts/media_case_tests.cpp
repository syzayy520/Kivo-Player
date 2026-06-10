#include <cassert>
#include <iostream>
#include "scenario/contracts/media_case/media_case_id.h"
#include "scenario/contracts/media_case/media_duration_class.h"
#include "scenario/contracts/media_case/media_track_layout_class.h"
#include "scenario/contracts/media_case/media_case_descriptor.h"

namespace kivo::playback::scenario {
void run_media_case_tests() {
    MediaCaseId id1;
    assert(id1.value == 0);
    MediaCaseId id2{789};
    assert(id2.value == 789);

    MediaDurationClass d1 = MediaDurationClass::Short;
    MediaDurationClass d2 = MediaDurationClass::Medium;
    MediaDurationClass d3 = MediaDurationClass::Long;
    MediaDurationClass d4 = MediaDurationClass::VeryLong;
    assert(d1 != d2); assert(d2 != d3); assert(d3 != d4);

    MediaTrackLayoutClass l1 = MediaTrackLayoutClass::AudioOnly;
    MediaTrackLayoutClass l2 = MediaTrackLayoutClass::VideoOnly;
    MediaTrackLayoutClass l3 = MediaTrackLayoutClass::AudioVideo;
    MediaTrackLayoutClass l4 = MediaTrackLayoutClass::MultiTrack;
    assert(l1 != l2); assert(l2 != l3); assert(l3 != l4);

    MediaCaseDescriptor desc1;
    assert(desc1.case_id.value == 0);
    assert(desc1.duration_class == MediaDurationClass::Unknown);
    assert(desc1.track_layout == MediaTrackLayoutClass::Unknown);
    MediaCaseDescriptor desc2{.case_id{300}, .duration_class{MediaDurationClass::Long}, .track_layout{MediaTrackLayoutClass::AudioVideo}};
    assert(desc2.case_id.value == 300);
    assert(desc2.duration_class == MediaDurationClass::Long);
    assert(desc2.track_layout == MediaTrackLayoutClass::AudioVideo);

    std::cout << "  media_case_tests: ALL PASSED\n";
}
}
