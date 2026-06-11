#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_integrity_view {

struct P2PublicSurfaceIntegrityViewSequenceId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceIntegrityViewSequenceId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_integrity_view
