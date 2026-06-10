// Copyright (c) 2026 Kivo Project. All rights reserved.
#pragma once
namespace kivo::playback::presentation {
struct PresentationWatermark { int min_units{0}; int max_units{0}; int target_units{0}; };
struct PresentationQueuePolicy { PresentationWatermark watermark{}; bool hold_last_on_pause{false}; bool minimal_queue_after_seek{false}; bool reject_stale_generation{false}; };
}
