#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_persistence_view {

struct P2PublicSurfacePersistenceViewGeneration {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfacePersistenceViewGeneration& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_persistence_view
