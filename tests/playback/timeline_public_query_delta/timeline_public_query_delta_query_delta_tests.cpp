#include <cassert>
#include <iostream>

#include "playback/timeline_public_query_delta/query_delta/playback_timeline_public_query_delta.h"

using namespace kivo::playback::timeline_public_query_delta;

void test_timeline_public_query_delta_query_delta_default_construction() {
    TimelinePublicQueryDeltaCandidate candidate{};
    assert(candidate.identity.query_delta_id.value == 0);
    assert(candidate.anchors.query_anchor.query_identity.query_id.value == 0);
    assert(candidate.classification.kind == TimelinePublicQueryDeltaKind::Unspecified);

    TimelinePublicQueryDeltaRecord record{};
    assert(record.identity.sequence_id.value == 0);
    assert(record.anchors.delta_anchor.delta_identity.delta_id.value == 0);
    assert(record.classification.scope == TimelinePublicQueryDeltaScope::Unspecified);

    TimelinePublicQueryDeltaEnvelope envelope{
        .candidate = candidate,
        .record = record
    };
    assert(envelope.candidate.identity.generation.value == 0);
    assert(envelope.record.identity.query_delta_id.value == 0);

    PlaybackTimelinePublicQueryDelta aggregate{
        .identity = TimelinePublicQueryDeltaIdentity{
            .query_delta_id = TimelinePublicQueryDeltaId{10},
            .sequence_id = TimelinePublicQueryDeltaSequenceId{11},
            .generation = TimelinePublicQueryDeltaGeneration{12}
        },
        .anchors = TimelinePublicQueryDeltaAnchorSet{},
        .classification = TimelinePublicQueryDeltaClassification{
            .kind = TimelinePublicQueryDeltaKind::FinalAuditLinked,
            .scope = TimelinePublicQueryDeltaScope::FinalAudit
        },
        .envelope = envelope
    };
    assert(aggregate.identity.query_delta_id.value == 10);
    assert(aggregate.classification.kind == TimelinePublicQueryDeltaKind::FinalAuditLinked);
    assert(aggregate.classification.scope == TimelinePublicQueryDeltaScope::FinalAudit);

    std::cout << "PASS: test_timeline_public_query_delta_query_delta_default_construction" << std::endl;
}
