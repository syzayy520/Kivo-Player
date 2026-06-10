#pragma once
namespace kivo::playback::audio {
enum class AudioRenderOutcomeStatus {
    Rendered,
    Dropped,
    Failed,
    Skipped,
    Unknown
};
}
