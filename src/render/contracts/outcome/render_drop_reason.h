#pragma once
namespace kivo::playback::render {
enum class RenderDropReason {
    LatePresentation,
    QueuePressure,
    PolicyOverride,
    GenerationStale,
    Unknown
};
}
