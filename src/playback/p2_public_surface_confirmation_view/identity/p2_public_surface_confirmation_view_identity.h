#pragma once

#include "p2_public_surface_confirmation_view_id.h"
#include "p2_public_surface_confirmation_view_sequence_id.h"
#include "p2_public_surface_confirmation_view_generation.h"

namespace kivo::playback::p2_public_surface_confirmation_view {

struct P2PublicSurfaceConfirmationViewIdentity {
    P2PublicSurfaceConfirmationViewId view_id{};
    P2PublicSurfaceConfirmationViewSequenceId sequence_id{};
    P2PublicSurfaceConfirmationViewGeneration generation{};

    bool operator==(const P2PublicSurfaceConfirmationViewIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_confirmation_view
