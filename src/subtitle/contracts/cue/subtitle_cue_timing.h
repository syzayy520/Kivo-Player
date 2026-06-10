#pragma once
#include "subtitle_cue_id.h"
#include "core/timeline/timestamp/media_timestamp.h"
namespace kivo::playback::subtitle {
struct SubtitleCueTiming {
    SubtitleCueId cue_id{};
    kivo::playback::timeline::MediaTimestamp start{};
    kivo::playback::timeline::MediaTimestamp end{};
};
}
