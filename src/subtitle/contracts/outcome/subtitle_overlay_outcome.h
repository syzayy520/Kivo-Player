#pragma once
#include "../composition/overlay_composition_id.h"
#include "subtitle_overlay_outcome_status.h"
namespace kivo::playback::subtitle {
struct SubtitleOverlayOutcome {
    OverlayCompositionId composition_id{};
    SubtitleOverlayOutcomeStatus status{SubtitleOverlayOutcomeStatus::Unknown};
};
}
