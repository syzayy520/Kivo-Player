#include <cassert>
#include <iostream>

#include "playback/timeline_public_query_delta/classification/timeline_public_query_delta_classification.h"

using namespace kivo::playback::timeline_public_query_delta;

void test_timeline_public_query_delta_classification_default_construction() {
    TimelinePublicQueryDeltaClassification classification{};
    assert(classification.kind == TimelinePublicQueryDeltaKind::Unspecified);
    assert(classification.scope == TimelinePublicQueryDeltaScope::Unspecified);

    TimelinePublicQueryDeltaClassification classification2{
        .kind = TimelinePublicQueryDeltaKind::QueryToDelta,
        .scope = TimelinePublicQueryDeltaScope::PublicTimeline
    };
    assert(classification2.kind == TimelinePublicQueryDeltaKind::QueryToDelta);
    assert(classification2.scope == TimelinePublicQueryDeltaScope::PublicTimeline);

    std::cout << "PASS: test_timeline_public_query_delta_classification_default_construction" << std::endl;
}
