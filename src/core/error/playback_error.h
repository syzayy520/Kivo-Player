// src/core/error/playback_error.h - Core error types.
// Depends on: standard library only.
#pragma once
#include <string>

namespace kivo::playback {

enum class PlaybackErrorType {
    InvalidCommand,
    InvalidStateTransition,
    OpenFailed,
    ProbeFailed,
    PipelineFailed,
    DecoderFailed,
    OutputFailed,
    UnsupportedCapability,
    Cancelled,
    InternalError,
};

struct PlaybackError {
    PlaybackErrorType type{};
    std::string message{};

    PlaybackError() = default;
    explicit PlaybackError(PlaybackErrorType t, std::string msg = {})
        : type(t), message(std::move(msg)) {}
    auto error_code_string() const -> std::string;
};

} // namespace kivo::playback
