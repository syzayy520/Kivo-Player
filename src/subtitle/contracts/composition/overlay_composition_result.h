#pragma once
#include <cstdint>
#include "overlay_composition_id.h"
#include "overlay_composition_status.h"
namespace kivo::playback::subtitle {
struct OverlayCompositionResult {
    OverlayCompositionId composition_id{};
    OverlayCompositionStatus status{OverlayCompositionStatus::Unknown};
    uint64_t cues_composed{0};
    uint64_t cues_dropped{0};
};
}
