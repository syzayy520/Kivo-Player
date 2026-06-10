#pragma once
namespace kivo::playback::audio {
enum class AudioRenderFailureReason {
    EndpointUnavailable,
    FormatIncompatible,
    SubmissionTimedOut,
    ResourceExhaustion,
    Unknown
};
}
