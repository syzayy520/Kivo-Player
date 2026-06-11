#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_snapshot {

enum class P2PublicSurfaceSnapshotStatus : std::uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_snapshot
