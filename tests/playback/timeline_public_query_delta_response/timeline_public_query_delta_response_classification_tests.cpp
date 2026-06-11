#include <cassert>
#include <iostream>

#include "playback/timeline_public_query_delta_response/classification/timeline_public_query_delta_response_classification.h"

using namespace kivo::playback::timeline_public_query_delta_response;

void test_query_delta_response_classification_default_construction() {
    TimelinePublicQueryDeltaResponseClassification classification{};
    assert(classification.kind == TimelinePublicQueryDeltaResponseKind::Unspecified);
    assert(classification.scope == TimelinePublicQueryDeltaResponseScope::Unspecified);

    TimelinePublicQueryDeltaResponseClassification classification2{
        .kind = TimelinePublicQueryDeltaResponseKind::QueryDeltaToResponse,
        .scope = TimelinePublicQueryDeltaResponseScope::PublicResponse
    };
    assert(classification2.kind == TimelinePublicQueryDeltaResponseKind::QueryDeltaToResponse);
    assert(classification2.scope == TimelinePublicQueryDeltaResponseScope::PublicResponse);

    std::cout << "PASS: test_query_delta_response_classification_default_construction" << std::endl;
}
