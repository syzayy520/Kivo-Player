// Copyright (c) 2026 Kivo Project. All rights reserved.
// src/core/id/playback_id.h - Core identity types for playback system.
// Depends on: standard library only.
// Does NOT depend on: any project module, media backends, UI, Windows headers.

#pragma once
#include <cstdint>
#include <string>

namespace kivo::playback {

// SessionId - identifies one opened media session.
// Opaque integer, no backend stream pointer, no third-party handle.
struct SessionId {
    std::uint64_t value{0};
    constexpr auto operator==(SessionId const&) const noexcept -> bool = default;
};

// CommandId - identifies one submitted command.
struct CommandId {
    std::uint64_t value{0};
    constexpr auto operator==(CommandId const&) const noexcept -> bool = default;
};

// GenerationId - used to reject stale command results after close/seek.
struct GenerationId {
    std::uint64_t value{0};
    constexpr auto operator==(GenerationId const&) const noexcept -> bool = default;
    auto operator++() noexcept -> GenerationId& { ++value; return *this; }
};

// TrackId - identifies an audio/subtitle track.
// 0 = invalid/none, positive = opaque placeholder.
struct TrackId {
    std::uint32_t value{0};
    constexpr auto operator==(TrackId const&) const noexcept -> bool = default;
    constexpr auto is_valid() const noexcept -> bool { return value != 0; }
};

// CapabilityId - placeholder for capability identification.
struct CapabilityId {
    std::uint64_t value{0};
    constexpr auto operator==(CapabilityId const&) const noexcept -> bool = default;
};

} // namespace kivo::playback
