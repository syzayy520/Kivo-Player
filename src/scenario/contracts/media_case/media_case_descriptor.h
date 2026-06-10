#pragma once
#include "media_case_id.h"
#include "media_duration_class.h"
#include "media_track_layout_class.h"
namespace kivo::playback::scenario {
struct MediaCaseDescriptor {
    MediaCaseId case_id{};
    MediaDurationClass duration_class{MediaDurationClass::Unknown};
    MediaTrackLayoutClass track_layout{MediaTrackLayoutClass::Unknown};
};
}
