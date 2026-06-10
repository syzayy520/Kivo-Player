#pragma once
namespace kivo::playback::audio {
enum class AudioRenderSubmissionStatus {
    Accepted,
    Partial,
    Rejected,
    Queued,
    Unknown
};
}
