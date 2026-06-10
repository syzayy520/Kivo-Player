#pragma once
namespace kivo::playback::audio {
enum class AudioRenderDropReason {
    LatePresentation,
    QueuePressure,
    GenerationStale,
    PolicyOverride,
    Unknown
};
}
