#pragma once

#include "p2_public_surface_integrity_view_id.h"
#include "p2_public_surface_integrity_view_sequence_id.h"
#include "p2_public_surface_integrity_view_generation.h"

namespace kivo::playback::p2_public_surface_integrity_view {

struct P2PublicSurfaceIntegrityViewIdentity {
    P2PublicSurfaceIntegrityViewId view_id{};
    P2PublicSurfaceIntegrityViewSequenceId sequence_id{};
    P2PublicSurfaceIntegrityViewGeneration generation{};

    bool operator==(const P2PublicSurfaceIntegrityViewIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_integrity_view
