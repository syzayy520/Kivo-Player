// src/core/result/playback_result.h - Command result model.
// Depends on: core/error, standard library.
// Does NOT depend on: UI messages, platform error types, backend error types.
#pragma once
#include "../error/playback_error.h"
#include <variant>

namespace kivo::playback {

struct PlaybackSuccess {};

struct PlaybackResult {
    std::variant<PlaybackSuccess, PlaybackError> value{};

    constexpr auto is_success() const noexcept -> bool {
        return std::holds_alternative<PlaybackSuccess>(value);
    }
    constexpr auto is_failure() const noexcept -> bool {
        return std::holds_alternative<PlaybackError>(value);
    }
    auto error() const -> PlaybackError const& {
        return std::get<PlaybackError>(value);
    }

    static auto success() -> PlaybackResult {
        return PlaybackResult{PlaybackSuccess{}};
    }
    static auto failure(PlaybackError const& e) -> PlaybackResult {
        return PlaybackResult{e};
    }
};

} // namespace kivo::playback
