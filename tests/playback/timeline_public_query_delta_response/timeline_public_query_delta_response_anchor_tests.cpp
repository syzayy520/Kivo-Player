#include <cassert>
#include <iostream>

#include "playback/timeline_public_query_delta_response/anchor/timeline_public_query_delta_response_anchor_set.h"

using namespace kivo::playback::timeline_public_query_delta_response;
using namespace kivo::playback::timeline_public_query_delta;
using namespace kivo::playback::timeline_public_response;
using namespace kivo::playback::p2_public_surface_final_audit;

void test_query_delta_response_anchor_default_construction() {
    TimelinePublicQueryDeltaResponseAnchorSet anchors{};
    assert(anchors.query_delta_anchor.query_delta_identity.query_delta_id.value == 0);
    assert(anchors.query_delta_anchor.query_delta_identity.sequence_id.value == 0);
    assert(anchors.query_delta_anchor.query_delta_identity.generation.value == 0);
    assert(anchors.response_anchor.response_identity.response_id.value == 0);
    assert(anchors.response_anchor.response_identity.sequence_id.value == 0);
    assert(anchors.response_anchor.response_identity.generation.value == 0);
    assert(anchors.final_audit_anchor.final_audit_identity.audit_id.value == 0);
    assert(anchors.final_audit_anchor.final_audit_identity.sequence_id.value == 0);
    assert(anchors.final_audit_anchor.final_audit_identity.generation.value == 0);

    TimelinePublicQueryDeltaResponseAnchorSet anchors2{
        .query_delta_anchor = TimelinePublicQueryDeltaResponseQueryDeltaAnchor{
            .query_delta_identity = TimelinePublicQueryDeltaIdentity{
                .query_delta_id = TimelinePublicQueryDeltaId{1},
                .sequence_id = TimelinePublicQueryDeltaSequenceId{2},
                .generation = TimelinePublicQueryDeltaGeneration{3}
            }
        },
        .response_anchor = TimelinePublicQueryDeltaResponseResponseAnchor{
            .response_identity = TimelinePublicResponseIdentity{
                .response_id = TimelinePublicResponseId{4},
                .sequence_id = TimelinePublicResponseSequenceId{5},
                .generation = TimelinePublicResponseGeneration{6}
            }
        },
        .final_audit_anchor = P2PublicSurfaceFinalAuditQueryDeltaResponseAnchor{
            .final_audit_identity = P2PublicSurfaceFinalAuditIdentity{
                .audit_id = P2PublicSurfaceFinalAuditId{7},
                .sequence_id = P2PublicSurfaceFinalAuditSequenceId{8},
                .generation = P2PublicSurfaceFinalAuditGeneration{9}
            }
        }
    };

    assert(anchors2.query_delta_anchor.query_delta_identity.query_delta_id.value == 1);
    assert(anchors2.response_anchor.response_identity.response_id.value == 4);
    assert(anchors2.final_audit_anchor.final_audit_identity.audit_id.value == 7);

    std::cout << "PASS: test_query_delta_response_anchor_default_construction" << std::endl;
}
