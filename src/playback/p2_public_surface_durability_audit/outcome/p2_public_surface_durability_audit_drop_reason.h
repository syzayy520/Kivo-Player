#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_durability_audit {

enum class P2PublicSurfaceDurabilityAuditDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_durability_audit
