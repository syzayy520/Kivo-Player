#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_persistence_view {

enum class P2PublicSurfacePersistenceViewDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_persistence_view
