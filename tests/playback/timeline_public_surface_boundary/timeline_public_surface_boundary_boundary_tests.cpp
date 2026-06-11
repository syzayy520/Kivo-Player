#include <cassert>
#include <iostream>

#include "playback/timeline_public_surface_boundary/boundary/playback_timeline_public_surface_boundary.h"
#include "playback/timeline_public_surface_boundary/boundary/timeline_public_surface_boundary_candidate.h"
#include "playback/timeline_public_surface_boundary/boundary/timeline_public_surface_boundary_envelope.h"
#include "playback/timeline_public_surface_boundary/boundary/timeline_public_surface_boundary_record.h"

using namespace kivo::playback::timeline_public_surface_boundary;

void test_surface_boundary_boundary_default_construction() {
    TimelinePublicSurfaceBoundaryCandidate candidate{};
    assert(candidate.identity.boundary_id.value == 0);
    assert(candidate.anchors.response_anchor.response_identity.response_id.value == 0);
    assert(candidate.classification.kind == TimelinePublicSurfaceBoundaryKind::Unknown);

    TimelinePublicSurfaceBoundaryCandidate candidate2{
        .identity = TimelinePublicSurfaceBoundaryIdentity{
            .boundary_id = TimelinePublicSurfaceBoundaryId{1}
        }
    };
    assert(candidate2.identity.boundary_id.value == 1);

    std::cout << "PASS: test_surface_boundary_candidate_default_construction" << std::endl;

    PlaybackTimelinePublicSurfaceBoundary boundary{};
    assert(boundary.identity.boundary_id.value == 0);
    assert(boundary.classification.kind == TimelinePublicSurfaceBoundaryKind::Unknown);

    PlaybackTimelinePublicSurfaceBoundary boundary2{
        .identity = TimelinePublicSurfaceBoundaryIdentity{
            .boundary_id = TimelinePublicSurfaceBoundaryId{10}
        },
        .classification = TimelinePublicSurfaceBoundaryClassification{
            .kind = TimelinePublicSurfaceBoundaryKind::Surface
        }
    };
    assert(boundary2.identity.boundary_id.value == 10);
    assert(boundary2.classification.kind == TimelinePublicSurfaceBoundaryKind::Surface);

    std::cout << "PASS: test_surface_boundary_default_construction" << std::endl;

    TimelinePublicSurfaceBoundaryEnvelope envelope{};
    assert(envelope.identity.boundary_id.value == 0);

    TimelinePublicSurfaceBoundaryEnvelope envelope2{
        .identity = TimelinePublicSurfaceBoundaryIdentity{
            .boundary_id = TimelinePublicSurfaceBoundaryId{20}
        }
    };
    assert(envelope2.identity.boundary_id.value == 20);

    std::cout << "PASS: test_surface_boundary_envelope_default_construction" << std::endl;

    TimelinePublicSurfaceBoundaryRecord record{};
    assert(record.envelope.identity.boundary_id.value == 0);
    assert(record.boundary.identity.boundary_id.value == 0);

    TimelinePublicSurfaceBoundaryRecord record2{
        .envelope = TimelinePublicSurfaceBoundaryEnvelope{
            .identity = TimelinePublicSurfaceBoundaryIdentity{
                .boundary_id = TimelinePublicSurfaceBoundaryId{30}
            }
        },
        .boundary = PlaybackTimelinePublicSurfaceBoundary{
            .identity = TimelinePublicSurfaceBoundaryIdentity{
                .boundary_id = TimelinePublicSurfaceBoundaryId{40}
            }
        }
    };
    assert(record2.envelope.identity.boundary_id.value == 30);
    assert(record2.boundary.identity.boundary_id.value == 40);

    std::cout << "PASS: test_surface_boundary_record_default_construction" << std::endl;

    record.envelope.identity.boundary_id = TimelinePublicSurfaceBoundaryId{50};
    record.boundary.identity.boundary_id = TimelinePublicSurfaceBoundaryId{60};

    assert(record.envelope.identity.boundary_id.value == 50);
    assert(record.boundary.identity.boundary_id.value == 60);

    std::cout << "PASS: test_surface_boundary_record_field_modification" << std::endl;
}
