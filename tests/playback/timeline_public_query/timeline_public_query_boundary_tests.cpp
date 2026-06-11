#include <cassert>
#include <iostream>

#include "playback/timeline_public_query/identity/timeline_public_query_identity.h"
#include "playback/timeline_public_query/anchor/timeline_public_delta_query_anchor.h"
#include "playback/timeline_public_query/query/playback_timeline_public_query.h"
#include "playback/timeline_public_query/outcome/timeline_public_query_outcome.h"

using namespace kivo::playback::timeline_public_query;

void test_query_boundary_cross_family() {
    {
        TimelinePublicDeltaQueryAnchor anchor{};
        assert(anchor.delta_identity.delta_id.value == 0);
        assert(anchor.delta_identity.sequence_id.value == 0);
        assert(anchor.delta_identity.generation.value == 0);

        anchor.delta_identity.delta_id = kivo::playback::timeline_public_delta::TimelinePublicDeltaId{123};
        assert(anchor.delta_identity.delta_id.value == 123);

        std::cout << "PASS: test_query_boundary_delta_anchor_cross_family" << std::endl;
    }

    {
        PlaybackTimelinePublicQuery query{
            .identity = TimelinePublicQueryIdentity{
                .query_id = TimelinePublicQueryId{1},
                .sequence_id = TimelinePublicQuerySequenceId{2},
                .generation = TimelinePublicQueryGeneration{3}
            },
            .anchors = TimelinePublicQueryAnchorSet{
                .delta_anchor = TimelinePublicDeltaQueryAnchor{
                    .delta_identity = kivo::playback::timeline_public_delta::TimelinePublicDeltaIdentity{
                        .delta_id = kivo::playback::timeline_public_delta::TimelinePublicDeltaId{10}
                    }
                }
            },
            .classification = TimelinePublicQueryClassification{
                .kind = TimelinePublicQueryKind::Snapshot,
                .scope = TimelinePublicQueryScope::Current
            }
        };

        assert(query.identity.query_id.value == 1);
        assert(query.identity.sequence_id.value == 2);
        assert(query.identity.generation.value == 3);
        assert(query.anchors.delta_anchor.delta_identity.delta_id.value == 10);
        assert(query.classification.kind == TimelinePublicQueryKind::Snapshot);
        assert(query.classification.scope == TimelinePublicQueryScope::Current);

        std::cout << "PASS: test_query_boundary_structural_completeness" << std::endl;
    }

    {
        TimelinePublicQueryOutcome outcome{
            .identity = TimelinePublicQueryIdentity{
                .query_id = TimelinePublicQueryId{42}
            },
            .status = TimelinePublicQueryStatus::Recorded
        };

        assert(outcome.identity.query_id.value == 42);
        assert(outcome.status == TimelinePublicQueryStatus::Recorded);
        assert(outcome.identity.sequence_id.value == 0);
        assert(outcome.identity.generation.value == 0);

        std::cout << "PASS: test_query_boundary_outcome_cross_family" << std::endl;
    }
}
