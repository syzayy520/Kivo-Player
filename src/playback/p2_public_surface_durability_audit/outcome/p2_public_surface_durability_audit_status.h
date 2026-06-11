#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_durability_audit {

enum class P2PublicSurfaceDurabilityAuditStatus : std::uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_durability_audit
