#include <cassert>
#include <iostream>

#include "playback/timeline_public_query/anchor/timeline_public_delta_query_anchor.h"
#include "playback/timeline_public_query/anchor/timeline_public_query_anchor_set.h"

using namespace kivo::playback::timeline_public_query;
using namespace kivo::playback::timeline_public_delta;

void test_query_anchor_default_construction() {
    TimelinePublicDeltaQueryAnchor anchor{};
    assert(anchor.delta_identity.delta_id.value == 0);
    assert(anchor.delta_identity.sequence_id.value == 0);
    assert(anchor.delta_identity.generation.value == 0);

    TimelinePublicDeltaQueryAnchor anchor2{
        .delta_identity = TimelinePublicDeltaIdentity{
            .delta_id = TimelinePublicDeltaId{5},
            .sequence_id = TimelinePublicDeltaSequenceId{10},
            .generation = TimelinePublicDeltaGeneration{15}
        }
    };
    assert(anchor2.delta_identity.delta_id.value == 5);
    assert(anchor2.delta_identity.sequence_id.value == 10);
    assert(anchor2.delta_identity.generation.value == 15);

    std::cout << "PASS: test_query_anchor_default_construction" << std::endl;

    TimelinePublicQueryAnchorSet anchor_set{};
    assert(anchor_set.delta_anchor.delta_identity.delta_id.value == 0);

    std::cout << "PASS: test_query_anchor_set_default_construction" << std::endl;
}

static void test_query_anchor_field_access() {
    TimelinePublicDeltaQueryAnchor anchor{
        .delta_identity = TimelinePublicDeltaIdentity{
            .delta_id = TimelinePublicDeltaId{77},
            .sequence_id = TimelinePublicDeltaSequenceId{88},
            .generation = TimelinePublicDeltaGeneration{99}
        }
    };
    assert(anchor.delta_identity.delta_id.value == 77);
    assert(anchor.delta_identity.sequence_id.value == 88);
    assert(anchor.delta_identity.generation.value == 99);

    std::cout << "PASS: test_query_anchor_field_access" << std::endl;
}
