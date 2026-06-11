#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_retention_view {

struct P2PublicSurfaceRetentionViewSequenceId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceRetentionViewSequenceId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_retention_view
