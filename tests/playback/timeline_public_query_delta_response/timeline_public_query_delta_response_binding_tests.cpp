#include <cassert>
#include <iostream>

#include "playback/timeline_public_query_delta_response/response_binding/playback_timeline_public_query_delta_response.h"

using namespace kivo::playback::timeline_public_query_delta_response;

void test_query_delta_response_binding_default_construction() {
    TimelinePublicQueryDeltaResponseCandidate candidate{};
    assert(candidate.identity.query_delta_response_key.value == 0);
    assert(candidate.anchors.query_delta_anchor.query_delta_identity.query_delta_id.value == 0);
    assert(candidate.classification.kind == TimelinePublicQueryDeltaResponseKind::Unspecified);

    TimelinePublicQueryDeltaResponseRecord record{};
    assert(record.identity.sequence_id.value == 0);
    assert(record.anchors.response_anchor.response_identity.response_id.value == 0);
    assert(record.classification.scope == TimelinePublicQueryDeltaResponseScope::Unspecified);

    TimelinePublicQueryDeltaResponseEnvelope envelope{
        .candidate = candidate,
        .record = record
    };
    assert(envelope.candidate.identity.generation.value == 0);
    assert(envelope.record.identity.query_delta_response_key.value == 0);

    PlaybackTimelinePublicQueryDeltaResponse aggregate{
        .identity = TimelinePublicQueryDeltaResponseIdentity{
            .query_delta_response_key = TimelinePublicQueryDeltaResponseKey{10},
            .sequence_id = TimelinePublicQueryDeltaResponseSequenceId{11},
            .generation = TimelinePublicQueryDeltaResponseGeneration{12}
        },
        .anchors = TimelinePublicQueryDeltaResponseAnchorSet{},
        .classification = TimelinePublicQueryDeltaResponseClassification{
            .kind = TimelinePublicQueryDeltaResponseKind::FinalAuditLinked,
            .scope = TimelinePublicQueryDeltaResponseScope::FinalAudit
        },
        .envelope = envelope
    };
    assert(aggregate.identity.query_delta_response_key.value == 10);
    assert(aggregate.classification.kind == TimelinePublicQueryDeltaResponseKind::FinalAuditLinked);
    assert(aggregate.classification.scope == TimelinePublicQueryDeltaResponseScope::FinalAudit);

    std::cout << "PASS: test_query_delta_response_binding_default_construction" << std::endl;
}
