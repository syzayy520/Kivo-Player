#pragma once

#include "p2_public_surface_activation_view_id.h"
#include "p2_public_surface_activation_view_sequence_id.h"
#include "p2_public_surface_activation_view_generation.h"

namespace kivo::playback::p2_public_surface_activation_view {

struct P2PublicSurfaceActivationViewIdentity {
    P2PublicSurfaceActivationViewId view_id{};
    P2PublicSurfaceActivationViewSequenceId sequence_id{};
    P2PublicSurfaceActivationViewGeneration generation{};

    bool operator==(const P2PublicSurfaceActivationViewIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_activation_view
