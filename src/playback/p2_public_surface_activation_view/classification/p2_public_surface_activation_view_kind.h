#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_activation_view {

enum class P2PublicSurfaceActivationViewKind : std::uint8_t {
    EligibilityActive,
    SurfaceActive,
    ProofActive,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_activation_view
