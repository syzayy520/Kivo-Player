#include <cassert>
#include <iostream>

#include "playback/timeline_public_query_delta/anchor/timeline_public_query_delta_anchor_set.h"

using namespace kivo::playback::timeline_public_query_delta;
using namespace kivo::playback::timeline_public_query;
using namespace kivo::playback::timeline_public_delta;
using namespace kivo::playback::p2_public_surface_final_audit;

void test_timeline_public_query_delta_anchor_default_construction() {
    TimelinePublicQueryDeltaAnchorSet anchors{};
    assert(anchors.query_anchor.query_identity.query_id.value == 0);
    assert(anchors.query_anchor.query_identity.sequence_id.value == 0);
    assert(anchors.query_anchor.query_identity.generation.value == 0);
    assert(anchors.delta_anchor.delta_identity.delta_id.value == 0);
    assert(anchors.delta_anchor.delta_identity.sequence_id.value == 0);
    assert(anchors.delta_anchor.delta_identity.generation.value == 0);
    assert(anchors.final_audit_anchor.final_audit_identity.audit_id.value == 0);
    assert(anchors.final_audit_anchor.final_audit_identity.sequence_id.value == 0);
    assert(anchors.final_audit_anchor.final_audit_identity.generation.value == 0);

    TimelinePublicQueryDeltaAnchorSet anchors2{
        .query_anchor = TimelinePublicQueryDeltaQueryAnchor{
            .query_identity = TimelinePublicQueryIdentity{
                .query_id = TimelinePublicQueryId{1},
                .sequence_id = TimelinePublicQuerySequenceId{2},
                .generation = TimelinePublicQueryGeneration{3}
            }
        },
        .delta_anchor = TimelinePublicQueryDeltaDeltaAnchor{
            .delta_identity = TimelinePublicDeltaIdentity{
                .delta_id = TimelinePublicDeltaId{4},
                .sequence_id = TimelinePublicDeltaSequenceId{5},
                .generation = TimelinePublicDeltaGeneration{6}
            }
        },
        .final_audit_anchor = P2PublicSurfaceFinalAuditQueryDeltaAnchor{
            .final_audit_identity = P2PublicSurfaceFinalAuditIdentity{
                .audit_id = P2PublicSurfaceFinalAuditId{7},
                .sequence_id = P2PublicSurfaceFinalAuditSequenceId{8},
                .generation = P2PublicSurfaceFinalAuditGeneration{9}
            }
        }
    };

    assert(anchors2.query_anchor.query_identity.query_id.value == 1);
    assert(anchors2.delta_anchor.delta_identity.delta_id.value == 4);
    assert(anchors2.final_audit_anchor.final_audit_identity.audit_id.value == 7);

    std::cout << "PASS: test_timeline_public_query_delta_anchor_default_construction" << std::endl;
}
