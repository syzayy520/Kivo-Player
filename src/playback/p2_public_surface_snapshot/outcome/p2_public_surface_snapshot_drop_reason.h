#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_snapshot {

enum class P2PublicSurfaceSnapshotDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_snapshot
