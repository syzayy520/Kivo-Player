#include <cassert>
#include <iostream>

#include "playback/session_public/identity/playback_session_public_identity.h"
#include "playback/session_public/anchor/playback_lifecycle_phase_session_public_anchor.h"
#include "playback/session_public/session/playback_session_public.h"
#include "playback/session_public/outcome/playback_session_public_outcome.h"

using namespace kivo::playback::session_public;

void test_session_public_boundary_cross_family() {
    {
        PlaybackLifecyclePhaseSessionPublicAnchor anchor{};
        assert(anchor.phase_identity.phase_id.value == 0);
        assert(anchor.phase_identity.sequence_id.value == 0);
        assert(anchor.phase_identity.generation.value == 0);

        anchor.phase_identity.phase_id = kivo::playback::lifecycle_phase::PlaybackLifecyclePhaseId{123};
        assert(anchor.phase_identity.phase_id.value == 123);

        std::cout << "PASS: test_session_public_boundary_phase_anchor" << std::endl;
    }

    {
        PlaybackSessionPublic session{
            .identity = PlaybackSessionPublicIdentity{
                .session_id = PlaybackSessionPublicId{1},
                .sequence_id = PlaybackSessionPublicSequenceId{2},
                .generation = PlaybackSessionPublicGeneration{3}
            },
            .anchors = PlaybackSessionPublicAnchorSet{
                .phase_anchor = PlaybackLifecyclePhaseSessionPublicAnchor{
                    .phase_identity = kivo::playback::lifecycle_phase::PlaybackLifecyclePhaseIdentity{
                        .phase_id = kivo::playback::lifecycle_phase::PlaybackLifecyclePhaseId{10}
                    }
                }
            },
            .classification = PlaybackSessionPublicClassification{
                .kind = PlaybackSessionPublicKind::Created,
                .scope = PlaybackSessionPublicScope::Session
            }
        };

        assert(session.identity.session_id.value == 1);
        assert(session.identity.sequence_id.value == 2);
        assert(session.identity.generation.value == 3);
        assert(session.anchors.phase_anchor.phase_identity.phase_id.value == 10);
        assert(session.classification.kind == PlaybackSessionPublicKind::Created);
        assert(session.classification.scope == PlaybackSessionPublicScope::Session);

        std::cout << "PASS: test_session_public_boundary_structural_completeness" << std::endl;
    }

    {
        PlaybackSessionPublicOutcome outcome{
            .identity = PlaybackSessionPublicIdentity{
                .session_id = PlaybackSessionPublicId{42}
            },
            .status = PlaybackSessionPublicStatus::Recorded
        };

        assert(outcome.identity.session_id.value == 42);
        assert(outcome.status == PlaybackSessionPublicStatus::Recorded);
        assert(outcome.identity.sequence_id.value == 0);
        assert(outcome.identity.generation.value == 0);

        std::cout << "PASS: test_session_public_boundary_outcome" << std::endl;
    }
}
