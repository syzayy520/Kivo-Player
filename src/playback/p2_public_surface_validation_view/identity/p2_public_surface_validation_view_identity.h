#pragma once

#include "p2_public_surface_validation_view_id.h"
#include "p2_public_surface_validation_view_sequence_id.h"
#include "p2_public_surface_validation_view_generation.h"

namespace kivo::playback::p2_public_surface_validation_view {

struct P2PublicSurfaceValidationViewIdentity {
    P2PublicSurfaceValidationViewId view_id{};
    P2PublicSurfaceValidationViewSequenceId sequence_id{};
    P2PublicSurfaceValidationViewGeneration generation{};

    bool operator==(const P2PublicSurfaceValidationViewIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_validation_view
