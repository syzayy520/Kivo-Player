#pragma once
#include "core/timeline/timestamp/media_timestamp.h"
#include "core/presentation/timing/presentation_deadline.h"
namespace kivo::playback::render {
struct RenderFrameTiming {
    kivo::playback::timeline::MediaTimestamp pts{};
    kivo::playback::presentation::PresentationDeadline deadline{};
};
}
