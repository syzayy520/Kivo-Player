#include <cassert>
#include <iostream>
#include "subtitle/contracts/region/subtitle_region_id.h"
#include "subtitle/contracts/region/subtitle_region_rect.h"
#include "subtitle/contracts/region/subtitle_placement.h"

namespace kivo::playback::subtitle {
void run_subtitle_region_tests() {
    // Test SubtitleRegionId
    SubtitleRegionId id1;
    assert(id1.value == 0);
    SubtitleRegionId id2{789};
    assert(id2.value == 789);

    // Test SubtitleRegionRect
    SubtitleRegionRect rect1;
    assert(rect1.left == 0.0);
    assert(rect1.top == 0.0);
    assert(rect1.width == 0.0);
    assert(rect1.height == 0.0);
    SubtitleRegionRect rect2{.left{0.1}, .top{0.8}, .width{0.8}, .height{0.15}};
    assert(rect2.left == 0.1);
    assert(rect2.width == 0.8);

    // Test SubtitlePlacement
    SubtitlePlacement placement1;
    assert(placement1.cue_id.value == 0);
    assert(placement1.region_id.value == 0);
    SubtitlePlacement placement2{.cue_id{111}, .region_id{222}};
    assert(placement2.cue_id.value == 111);
    assert(placement2.region_id.value == 222);

    std::cout << "  subtitle_region_tests: ALL PASSED\n";
}
}
