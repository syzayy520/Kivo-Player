#include <cassert>
#include <iostream>

#include "playback/timeline_public_response/identity/timeline_public_response_identity.h"
#include "playback/timeline_public_response/anchor/timeline_public_query_response_anchor.h"
#include "playback/timeline_public_response/response/playback_timeline_public_response.h"
#include "playback/timeline_public_response/outcome/timeline_public_response_outcome.h"

using namespace kivo::playback::timeline_public_response;

void test_response_boundary_cross_family() {
    {
        TimelinePublicQueryResponseAnchor anchor{};
        assert(anchor.query_identity.query_id.value == 0);
        assert(anchor.query_identity.sequence_id.value == 0);
        assert(anchor.query_identity.generation.value == 0);

        anchor.query_identity.query_id = kivo::playback::timeline_public_query::TimelinePublicQueryId{123};
        assert(anchor.query_identity.query_id.value == 123);

        std::cout << "PASS: test_response_boundary_query_anchor_cross_family" << std::endl;
    }

    {
        PlaybackTimelinePublicResponse response{
            .identity = TimelinePublicResponseIdentity{
                .response_id = TimelinePublicResponseId{1},
                .sequence_id = TimelinePublicResponseSequenceId{2},
                .generation = TimelinePublicResponseGeneration{3}
            },
            .anchors = TimelinePublicResponseAnchorSet{
                .query_anchor = TimelinePublicQueryResponseAnchor{
                    .query_identity = kivo::playback::timeline_public_query::TimelinePublicQueryIdentity{
                        .query_id = kivo::playback::timeline_public_query::TimelinePublicQueryId{10}
                    }
                }
            },
            .classification = TimelinePublicResponseClassification{
                .kind = TimelinePublicResponseKind::Snapshot,
                .scope = TimelinePublicResponseScope::Current
            }
        };

        assert(response.identity.response_id.value == 1);
        assert(response.identity.sequence_id.value == 2);
        assert(response.identity.generation.value == 3);
        assert(response.anchors.query_anchor.query_identity.query_id.value == 10);
        assert(response.classification.kind == TimelinePublicResponseKind::Snapshot);
        assert(response.classification.scope == TimelinePublicResponseScope::Current);

        std::cout << "PASS: test_response_boundary_structural_completeness" << std::endl;
    }

    {
        TimelinePublicResponseOutcome outcome{
            .identity = TimelinePublicResponseIdentity{
                .response_id = TimelinePublicResponseId{42}
            },
            .status = TimelinePublicResponseStatus::Recorded
        };

        assert(outcome.identity.response_id.value == 42);
        assert(outcome.status == TimelinePublicResponseStatus::Recorded);
        assert(outcome.identity.sequence_id.value == 0);
        assert(outcome.identity.generation.value == 0);

        std::cout << "PASS: test_response_boundary_outcome_cross_family" << std::endl;
    }
}
