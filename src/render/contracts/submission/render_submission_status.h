#pragma once
namespace kivo::playback::render {
enum class RenderSubmissionStatus {
    Queued,
    InProgress,
    Completed,
    Dropped,
    Failed
};
}
