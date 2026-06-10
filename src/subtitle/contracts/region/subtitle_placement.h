#pragma once
#include "subtitle_region_id.h"
#include "../cue/subtitle_cue_id.h"
namespace kivo::playback::subtitle {
struct SubtitlePlacement {
    SubtitleCueId cue_id{};
    SubtitleRegionId region_id{};
};
}
