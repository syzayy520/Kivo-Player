#pragma once
namespace kivo::playback::render {
enum class RenderOutcomeStatus {
    Rendered,
    Dropped,
    Failed,
    Skipped,
    Unknown
};
}
