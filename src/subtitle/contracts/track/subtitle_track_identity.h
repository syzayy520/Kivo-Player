#pragma once
#include "subtitle_track_id.h"
#include "subtitle_track_role.h"
namespace kivo::playback::subtitle {
struct SubtitleTrackIdentity {
    SubtitleTrackId id{};
    SubtitleTrackRole role{SubtitleTrackRole::Unknown};
};
}
