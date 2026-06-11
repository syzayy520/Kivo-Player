#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_coherence_view {

enum class P2PublicSurfaceCoherenceViewRejectionReason : std::uint8_t {
    IntegrityAnchorMissing,
    ClassificationInvalid,
    ViewIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_coherence_view
