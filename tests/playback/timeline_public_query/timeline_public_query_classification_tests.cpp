#include <cassert>
#include <iostream>

#include "playback/timeline_public_query/classification/timeline_public_query_classification.h"

using namespace kivo::playback::timeline_public_query;

static void test_query_kind_enum_values() {
    assert(static_cast<uint8_t>(TimelinePublicQueryKind::Snapshot) == 0);
    assert(static_cast<uint8_t>(TimelinePublicQueryKind::Delta) == 1);
    assert(static_cast<uint8_t>(TimelinePublicQueryKind::Status) == 2);
    assert(static_cast<uint8_t>(TimelinePublicQueryKind::Unknown) == 3);
    std::cout << "PASS: test_query_kind_enum_values" << std::endl;
}

static void test_query_scope_enum_values() {
    assert(static_cast<uint8_t>(TimelinePublicQueryScope::Current) == 0);
    assert(static_cast<uint8_t>(TimelinePublicQueryScope::Since) == 1);
    assert(static_cast<uint8_t>(TimelinePublicQueryScope::Window) == 2);
    assert(static_cast<uint8_t>(TimelinePublicQueryScope::PublicSafe) == 3);
    assert(static_cast<uint8_t>(TimelinePublicQueryScope::Unknown) == 4);
    std::cout << "PASS: test_query_scope_enum_values" << std::endl;
}

void test_query_classification_default_construction() {
    test_query_kind_enum_values();
    test_query_scope_enum_values();

    TimelinePublicQueryClassification cls{};
    assert(cls.kind == TimelinePublicQueryKind::Unknown);
    assert(cls.scope == TimelinePublicQueryScope::Unknown);

    TimelinePublicQueryClassification cls2{
        .kind = TimelinePublicQueryKind::Snapshot,
        .scope = TimelinePublicQueryScope::Current
    };
    assert(cls2.kind == TimelinePublicQueryKind::Snapshot);
    assert(cls2.scope == TimelinePublicQueryScope::Current);

    assert(cls == cls);
    assert(!(cls == cls2));

    std::cout << "PASS: test_query_classification_default_construction" << std::endl;

    cls.kind = TimelinePublicQueryKind::Status;
    cls.scope = TimelinePublicQueryScope::Window;
    assert(cls.kind == TimelinePublicQueryKind::Status);
    assert(cls.scope == TimelinePublicQueryScope::Window);

    std::cout << "PASS: test_query_classification_field_modification" << std::endl;
}
