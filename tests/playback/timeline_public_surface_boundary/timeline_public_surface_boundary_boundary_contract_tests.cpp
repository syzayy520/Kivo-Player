#include <cassert>
#include <iostream>

#include "playback/timeline_public_surface_boundary/identity/timeline_public_surface_boundary_identity.h"
#include "playback/timeline_public_surface_boundary/anchor/timeline_public_response_surface_boundary_anchor.h"
#include "playback/timeline_public_surface_boundary/boundary/playback_timeline_public_surface_boundary.h"
#include "playback/timeline_public_surface_boundary/outcome/timeline_public_surface_boundary_outcome.h"

using namespace kivo::playback::timeline_public_surface_boundary;

void test_surface_boundary_contract_default_construction() {
    {
        TimelinePublicResponseSurfaceBoundaryAnchor anchor{};
        assert(anchor.response_identity.response_id.value == 0);
        assert(anchor.response_identity.sequence_id.value == 0);
        assert(anchor.response_identity.generation.value == 0);

        anchor.response_identity.response_id = kivo::playback::timeline_public_response::TimelinePublicResponseId{123};
        assert(anchor.response_identity.response_id.value == 123);

        std::cout << "PASS: test_surface_boundary_contract_response_anchor" << std::endl;
    }

    {
        PlaybackTimelinePublicSurfaceBoundary boundary{
            .identity = TimelinePublicSurfaceBoundaryIdentity{
                .boundary_id = TimelinePublicSurfaceBoundaryId{1},
                .sequence_id = TimelinePublicSurfaceBoundarySequenceId{2},
                .generation = TimelinePublicSurfaceBoundaryGeneration{3}
            },
            .anchors = TimelinePublicSurfaceBoundaryAnchorSet{
                .response_anchor = TimelinePublicResponseSurfaceBoundaryAnchor{
                    .response_identity = kivo::playback::timeline_public_response::TimelinePublicResponseIdentity{
                        .response_id = kivo::playback::timeline_public_response::TimelinePublicResponseId{10}
                    }
                }
            },
            .classification = TimelinePublicSurfaceBoundaryClassification{
                .kind = TimelinePublicSurfaceBoundaryKind::Surface,
                .scope = TimelinePublicSurfaceBoundaryScope::PublicSafe
            }
        };

        assert(boundary.identity.boundary_id.value == 1);
        assert(boundary.identity.sequence_id.value == 2);
        assert(boundary.identity.generation.value == 3);
        assert(boundary.anchors.response_anchor.response_identity.response_id.value == 10);
        assert(boundary.classification.kind == TimelinePublicSurfaceBoundaryKind::Surface);
        assert(boundary.classification.scope == TimelinePublicSurfaceBoundaryScope::PublicSafe);

        std::cout << "PASS: test_surface_boundary_contract_structural_completeness" << std::endl;
    }

    {
        TimelinePublicSurfaceBoundaryOutcome outcome{
            .identity = TimelinePublicSurfaceBoundaryIdentity{
                .boundary_id = TimelinePublicSurfaceBoundaryId{42}
            },
            .status = TimelinePublicSurfaceBoundaryStatus::Recorded
        };

        assert(outcome.identity.boundary_id.value == 42);
        assert(outcome.status == TimelinePublicSurfaceBoundaryStatus::Recorded);
        assert(outcome.identity.sequence_id.value == 0);
        assert(outcome.identity.generation.value == 0);

        std::cout << "PASS: test_surface_boundary_contract_outcome" << std::endl;
    }
}
