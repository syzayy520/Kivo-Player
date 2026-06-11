#include <cassert>
#include <iostream>

#include "playback/timeline_public_response/response/playback_timeline_public_response.h"
#include "playback/timeline_public_response/response/timeline_public_response_candidate.h"
#include "playback/timeline_public_response/response/timeline_public_response_envelope.h"
#include "playback/timeline_public_response/response/timeline_public_response_record.h"

using namespace kivo::playback::timeline_public_response;

void test_response_response_default_construction() {
    TimelinePublicResponseCandidate candidate{};
    assert(candidate.identity.response_id.value == 0);
    assert(candidate.anchors.query_anchor.query_identity.query_id.value == 0);
    assert(candidate.classification.kind == TimelinePublicResponseKind::Unknown);

    TimelinePublicResponseCandidate candidate2{
        .identity = TimelinePublicResponseIdentity{
            .response_id = TimelinePublicResponseId{1}
        }
    };
    assert(candidate2.identity.response_id.value == 1);

    std::cout << "PASS: test_response_candidate_default_construction" << std::endl;

    PlaybackTimelinePublicResponse response{};
    assert(response.identity.response_id.value == 0);
    assert(response.classification.kind == TimelinePublicResponseKind::Unknown);

    PlaybackTimelinePublicResponse response2{
        .identity = TimelinePublicResponseIdentity{
            .response_id = TimelinePublicResponseId{10}
        },
        .classification = TimelinePublicResponseClassification{
            .kind = TimelinePublicResponseKind::Snapshot
        }
    };
    assert(response2.identity.response_id.value == 10);
    assert(response2.classification.kind == TimelinePublicResponseKind::Snapshot);

    std::cout << "PASS: test_response_default_construction" << std::endl;

    TimelinePublicResponseEnvelope envelope{};
    assert(envelope.identity.response_id.value == 0);

    TimelinePublicResponseEnvelope envelope2{
        .identity = TimelinePublicResponseIdentity{
            .response_id = TimelinePublicResponseId{20}
        }
    };
    assert(envelope2.identity.response_id.value == 20);

    std::cout << "PASS: test_response_envelope_default_construction" << std::endl;

    TimelinePublicResponseRecord record{};
    assert(record.envelope.identity.response_id.value == 0);
    assert(record.response.identity.response_id.value == 0);

    TimelinePublicResponseRecord record2{
        .envelope = TimelinePublicResponseEnvelope{
            .identity = TimelinePublicResponseIdentity{
                .response_id = TimelinePublicResponseId{30}
            }
        },
        .response = PlaybackTimelinePublicResponse{
            .identity = TimelinePublicResponseIdentity{
                .response_id = TimelinePublicResponseId{40}
            }
        }
    };
    assert(record2.envelope.identity.response_id.value == 30);
    assert(record2.response.identity.response_id.value == 40);

    std::cout << "PASS: test_response_record_default_construction" << std::endl;

    record.envelope.identity.response_id = TimelinePublicResponseId{50};
    record.response.identity.response_id = TimelinePublicResponseId{60};

    assert(record.envelope.identity.response_id.value == 50);
    assert(record.response.identity.response_id.value == 60);

    std::cout << "PASS: test_response_record_field_modification" << std::endl;
}
