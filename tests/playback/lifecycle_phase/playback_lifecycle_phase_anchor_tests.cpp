#include <cassert>
#include <iostream>

#include "playback/lifecycle_phase/anchor/timeline_public_surface_boundary_lifecycle_phase_anchor.h"
#include "playback/lifecycle_phase/anchor/playback_lifecycle_phase_anchor_set.h"

using namespace kivo::playback::lifecycle_phase;
using namespace kivo::playback::timeline_public_surface_boundary;

void test_lifecycle_phase_anchor_default_construction() {
    TimelinePublicSurfaceBoundaryLifecyclePhaseAnchor anchor{};
    assert(anchor.boundary_identity.boundary_id.value == 0);
    assert(anchor.boundary_identity.sequence_id.value == 0);
    assert(anchor.boundary_identity.generation.value == 0);

    TimelinePublicSurfaceBoundaryLifecyclePhaseAnchor anchor2{
        .boundary_identity = TimelinePublicSurfaceBoundaryIdentity{
            .boundary_id = TimelinePublicSurfaceBoundaryId{5},
            .sequence_id = TimelinePublicSurfaceBoundarySequenceId{10},
            .generation = TimelinePublicSurfaceBoundaryGeneration{15}
        }
    };
    assert(anchor2.boundary_identity.boundary_id.value == 5);
    assert(anchor2.boundary_identity.sequence_id.value == 10);
    assert(anchor2.boundary_identity.generation.value == 15);

    std::cout << "PASS: test_lifecycle_phase_anchor_default_construction" << std::endl;

    PlaybackLifecyclePhaseAnchorSet anchor_set{};
    assert(anchor_set.boundary_anchor.boundary_identity.boundary_id.value == 0);

    std::cout << "PASS: test_lifecycle_phase_anchor_set_default_construction" << std::endl;
}
