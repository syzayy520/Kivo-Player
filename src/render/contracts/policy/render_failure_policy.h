#pragma once
namespace kivo::playback::render {
enum class RenderFailurePolicy {
    AbortSubmission,
    SkipFrame,
    RetryOnce,
    NotifyAndContinue,
    Unknown
};
}
