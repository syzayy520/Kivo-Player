#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_state_view {

enum class P2PublicSurfaceStateViewRejectionReason : std::uint8_t {
    ClosureAnchorMissing,
    ClassificationInvalid,
    ViewIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_state_view
