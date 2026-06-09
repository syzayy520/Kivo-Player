// src/core/capability/playback_capability.h - Capability model base types.
#pragma once
namespace kivo::playback {
enum class CapabilityStatus {
    Unknown, Detected, Parsed, Supported,
    OutputAvailable, Verified, Unsupported
};
} // namespace kivo::playback
