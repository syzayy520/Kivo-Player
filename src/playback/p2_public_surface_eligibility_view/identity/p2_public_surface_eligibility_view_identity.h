#pragma once

#include "p2_public_surface_eligibility_view_id.h"
#include "p2_public_surface_eligibility_view_sequence_id.h"
#include "p2_public_surface_eligibility_view_generation.h"

namespace kivo::playback::p2_public_surface_eligibility_view {

struct P2PublicSurfaceEligibilityViewIdentity {
    P2PublicSurfaceEligibilityViewId view_id{};
    P2PublicSurfaceEligibilityViewSequenceId sequence_id{};
    P2PublicSurfaceEligibilityViewGeneration generation{};

    bool operator==(const P2PublicSurfaceEligibilityViewIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_eligibility_view
