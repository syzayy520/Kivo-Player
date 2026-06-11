#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_progress_view {

enum class P2PublicSurfaceProgressViewRejectionReason : std::uint8_t {
    StateViewAnchorMissing,
    ClassificationInvalid,
    ViewIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_progress_view
