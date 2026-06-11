#include <cassert>
#include <iostream>

#include "playback/lifecycle_phase/identity/playback_lifecycle_phase_identity.h"
#include "playback/lifecycle_phase/anchor/timeline_public_surface_boundary_lifecycle_phase_anchor.h"
#include "playback/lifecycle_phase/phase/playback_lifecycle_phase.h"
#include "playback/lifecycle_phase/outcome/playback_lifecycle_phase_outcome.h"

using namespace kivo::playback::lifecycle_phase;

void test_lifecycle_phase_boundary_cross_family() {
    {
        TimelinePublicSurfaceBoundaryLifecyclePhaseAnchor anchor{};
        assert(anchor.boundary_identity.boundary_id.value == 0);
        assert(anchor.boundary_identity.sequence_id.value == 0);
        assert(anchor.boundary_identity.generation.value == 0);

        anchor.boundary_identity.boundary_id = kivo::playback::timeline_public_surface_boundary::TimelinePublicSurfaceBoundaryId{123};
        assert(anchor.boundary_identity.boundary_id.value == 123);

        std::cout << "PASS: test_lifecycle_phase_boundary_surface_anchor" << std::endl;
    }

    {
        PlaybackLifecyclePhase phase{
            .identity = PlaybackLifecyclePhaseIdentity{
                .phase_id = PlaybackLifecyclePhaseId{1},
                .sequence_id = PlaybackLifecyclePhaseSequenceId{2},
                .generation = PlaybackLifecyclePhaseGeneration{3}
            },
            .anchors = PlaybackLifecyclePhaseAnchorSet{
                .boundary_anchor = TimelinePublicSurfaceBoundaryLifecyclePhaseAnchor{
                    .boundary_identity = kivo::playback::timeline_public_surface_boundary::TimelinePublicSurfaceBoundaryIdentity{
                        .boundary_id = kivo::playback::timeline_public_surface_boundary::TimelinePublicSurfaceBoundaryId{10}
                    }
                }
            },
            .classification = PlaybackLifecyclePhaseClassification{
                .kind = PlaybackLifecyclePhaseKind::Created,
                .scope = PlaybackLifecyclePhaseScope::PublicSurface
            }
        };

        assert(phase.identity.phase_id.value == 1);
        assert(phase.identity.sequence_id.value == 2);
        assert(phase.identity.generation.value == 3);
        assert(phase.anchors.boundary_anchor.boundary_identity.boundary_id.value == 10);
        assert(phase.classification.kind == PlaybackLifecyclePhaseKind::Created);
        assert(phase.classification.scope == PlaybackLifecyclePhaseScope::PublicSurface);

        std::cout << "PASS: test_lifecycle_phase_boundary_structural_completeness" << std::endl;
    }

    {
        PlaybackLifecyclePhaseOutcome outcome{
            .identity = PlaybackLifecyclePhaseIdentity{
                .phase_id = PlaybackLifecyclePhaseId{42}
            },
            .status = PlaybackLifecyclePhaseStatus::Recorded
        };

        assert(outcome.identity.phase_id.value == 42);
        assert(outcome.status == PlaybackLifecyclePhaseStatus::Recorded);
        assert(outcome.identity.sequence_id.value == 0);
        assert(outcome.identity.generation.value == 0);

        std::cout << "PASS: test_lifecycle_phase_boundary_outcome" << std::endl;
    }
}
