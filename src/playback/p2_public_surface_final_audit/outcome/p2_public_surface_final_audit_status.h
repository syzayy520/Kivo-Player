#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_final_audit {

enum class P2PublicSurfaceFinalAuditStatus : std::uint8_t {
    Recorded,
    Rejected,
    Deferred,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_final_audit
