#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_progress_view {

struct P2PublicSurfaceProgressViewSequenceId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceProgressViewSequenceId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_progress_view
