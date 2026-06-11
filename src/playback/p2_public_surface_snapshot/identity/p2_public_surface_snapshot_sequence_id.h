#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_snapshot {

struct P2PublicSurfaceSnapshotSequenceId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceSnapshotSequenceId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_snapshot
