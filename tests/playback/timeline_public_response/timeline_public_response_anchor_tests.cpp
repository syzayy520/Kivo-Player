#include <cassert>
#include <iostream>

#include "playback/timeline_public_response/anchor/timeline_public_query_response_anchor.h"
#include "playback/timeline_public_response/anchor/timeline_public_response_anchor_set.h"

using namespace kivo::playback::timeline_public_response;
using namespace kivo::playback::timeline_public_query;

void test_response_anchor_default_construction() {
    TimelinePublicQueryResponseAnchor anchor{};
    assert(anchor.query_identity.query_id.value == 0);
    assert(anchor.query_identity.sequence_id.value == 0);
    assert(anchor.query_identity.generation.value == 0);

    TimelinePublicQueryResponseAnchor anchor2{
        .query_identity = TimelinePublicQueryIdentity{
            .query_id = TimelinePublicQueryId{5},
            .sequence_id = TimelinePublicQuerySequenceId{10},
            .generation = TimelinePublicQueryGeneration{15}
        }
    };
    assert(anchor2.query_identity.query_id.value == 5);
    assert(anchor2.query_identity.sequence_id.value == 10);
    assert(anchor2.query_identity.generation.value == 15);

    std::cout << "PASS: test_response_anchor_default_construction" << std::endl;

    TimelinePublicResponseAnchorSet anchor_set{};
    assert(anchor_set.query_anchor.query_identity.query_id.value == 0);

    std::cout << "PASS: test_response_anchor_set_default_construction" << std::endl;
}

static void test_response_anchor_field_access() {
    TimelinePublicQueryResponseAnchor anchor{
        .query_identity = TimelinePublicQueryIdentity{
            .query_id = TimelinePublicQueryId{77},
            .sequence_id = TimelinePublicQuerySequenceId{88},
            .generation = TimelinePublicQueryGeneration{99}
        }
    };
    assert(anchor.query_identity.query_id.value == 77);
    assert(anchor.query_identity.sequence_id.value == 88);
    assert(anchor.query_identity.generation.value == 99);

    std::cout << "PASS: test_response_anchor_field_access" << std::endl;
}
