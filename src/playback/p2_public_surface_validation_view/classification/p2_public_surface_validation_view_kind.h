#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_validation_view {

enum class P2PublicSurfaceValidationViewKind : std::uint8_t {
    ConfirmationValidated,
    SurfaceValidated,
    ProofValidated,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_validation_view
