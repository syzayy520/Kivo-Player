#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_integrity_view {

enum class P2PublicSurfaceIntegrityViewDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_integrity_view
