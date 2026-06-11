#include <cassert>
#include <iostream>

#include "playback/timeline_public_surface_boundary/anchor/timeline_public_response_surface_boundary_anchor.h"
#include "playback/timeline_public_surface_boundary/anchor/timeline_public_surface_boundary_anchor_set.h"

using namespace kivo::playback::timeline_public_surface_boundary;
using namespace kivo::playback::timeline_public_response;

void test_surface_boundary_anchor_default_construction() {
    TimelinePublicResponseSurfaceBoundaryAnchor anchor{};
    assert(anchor.response_identity.response_id.value == 0);
    assert(anchor.response_identity.sequence_id.value == 0);
    assert(anchor.response_identity.generation.value == 0);

    TimelinePublicResponseSurfaceBoundaryAnchor anchor2{
        .response_identity = TimelinePublicResponseIdentity{
            .response_id = TimelinePublicResponseId{5},
            .sequence_id = TimelinePublicResponseSequenceId{10},
            .generation = TimelinePublicResponseGeneration{15}
        }
    };
    assert(anchor2.response_identity.response_id.value == 5);
    assert(anchor2.response_identity.sequence_id.value == 10);
    assert(anchor2.response_identity.generation.value == 15);

    std::cout << "PASS: test_surface_boundary_anchor_default_construction" << std::endl;

    TimelinePublicSurfaceBoundaryAnchorSet anchor_set{};
    assert(anchor_set.response_anchor.response_identity.response_id.value == 0);

    std::cout << "PASS: test_surface_boundary_anchor_set_default_construction" << std::endl;
}
