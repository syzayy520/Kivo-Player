#pragma once
#include <vector>
#include "overlay_composition_id.h"
#include "../cue/subtitle_cue_id.h"
#include "../overlay/overlay_plane_id.h"
#include "core/timeline/timestamp/media_timestamp.h"
#include "core/presentation/timing/presentation_deadline.h"
namespace kivo::playback::subtitle {
struct OverlayCompositionRequest {
    OverlayCompositionId composition_id{};
    std::vector<SubtitleCueId> cue_ids{};
    OverlayPlaneId target_plane_id{};
    kivo::playback::timeline::MediaTimestamp presentation_timestamp{};
    kivo::playback::presentation::PresentationDeadline deadline{};
};
}
