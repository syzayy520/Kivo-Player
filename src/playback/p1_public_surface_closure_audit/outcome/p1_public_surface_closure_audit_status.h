#pragma once

#include <cstdint>

namespace kivo::playback::p1_public_surface_closure_audit {

enum class P1PublicSurfaceClosureAuditStatus : std::uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::p1_public_surface_closure_audit
