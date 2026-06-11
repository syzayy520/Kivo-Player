#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_persistence_view {

struct P2PublicSurfacePersistenceViewSequenceId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfacePersistenceViewSequenceId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_persistence_view
