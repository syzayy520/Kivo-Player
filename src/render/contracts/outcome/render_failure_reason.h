#pragma once
namespace kivo::playback::render {
enum class RenderFailureReason {
    TargetUnavailable,
    SurfaceInvalid,
    SubmissionTimedOut,
    ResourceExhaustion,
    Unknown
};
}
