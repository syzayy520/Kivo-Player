#pragma once
namespace kivo::playback::render {
enum class RenderSubmissionStatus {
    Accepted,
    Partial,
    Rejected,
    Queued,
    Unknown
};
}
