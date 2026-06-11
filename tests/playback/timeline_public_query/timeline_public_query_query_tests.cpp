#include <cassert>
#include <iostream>

#include "playback/timeline_public_query/query/playback_timeline_public_query.h"
#include "playback/timeline_public_query/query/timeline_public_query_candidate.h"
#include "playback/timeline_public_query/query/timeline_public_query_envelope.h"
#include "playback/timeline_public_query/query/timeline_public_query_record.h"

using namespace kivo::playback::timeline_public_query;

void test_query_query_default_construction() {
    TimelinePublicQueryCandidate candidate{};
    assert(candidate.identity.query_id.value == 0);
    assert(candidate.anchors.delta_anchor.delta_identity.delta_id.value == 0);
    assert(candidate.classification.kind == TimelinePublicQueryKind::Unknown);

    TimelinePublicQueryCandidate candidate2{
        .identity = TimelinePublicQueryIdentity{
            .query_id = TimelinePublicQueryId{1}
        }
    };
    assert(candidate2.identity.query_id.value == 1);

    std::cout << "PASS: test_query_candidate_default_construction" << std::endl;

    PlaybackTimelinePublicQuery query{};
    assert(query.identity.query_id.value == 0);
    assert(query.classification.kind == TimelinePublicQueryKind::Unknown);

    PlaybackTimelinePublicQuery query2{
        .identity = TimelinePublicQueryIdentity{
            .query_id = TimelinePublicQueryId{10}
        },
        .classification = TimelinePublicQueryClassification{
            .kind = TimelinePublicQueryKind::Snapshot
        }
    };
    assert(query2.identity.query_id.value == 10);
    assert(query2.classification.kind == TimelinePublicQueryKind::Snapshot);

    std::cout << "PASS: test_query_default_construction" << std::endl;

    TimelinePublicQueryEnvelope envelope{};
    assert(envelope.identity.query_id.value == 0);

    TimelinePublicQueryEnvelope envelope2{
        .identity = TimelinePublicQueryIdentity{
            .query_id = TimelinePublicQueryId{20}
        }
    };
    assert(envelope2.identity.query_id.value == 20);

    std::cout << "PASS: test_query_envelope_default_construction" << std::endl;

    TimelinePublicQueryRecord record{};
    assert(record.envelope.identity.query_id.value == 0);
    assert(record.query.identity.query_id.value == 0);

    TimelinePublicQueryRecord record2{
        .envelope = TimelinePublicQueryEnvelope{
            .identity = TimelinePublicQueryIdentity{
                .query_id = TimelinePublicQueryId{30}
            }
        },
        .query = PlaybackTimelinePublicQuery{
            .identity = TimelinePublicQueryIdentity{
                .query_id = TimelinePublicQueryId{40}
            }
        }
    };
    assert(record2.envelope.identity.query_id.value == 30);
    assert(record2.query.identity.query_id.value == 40);

    std::cout << "PASS: test_query_record_default_construction" << std::endl;

    record.envelope.identity.query_id = TimelinePublicQueryId{50};
    record.query.identity.query_id = TimelinePublicQueryId{60};

    assert(record.envelope.identity.query_id.value == 50);
    assert(record.query.identity.query_id.value == 60);

    std::cout << "PASS: test_query_record_field_modification" << std::endl;
}
