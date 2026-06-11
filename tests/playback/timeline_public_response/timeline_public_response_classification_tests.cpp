#include <cassert>
#include <iostream>

#include "playback/timeline_public_response/classification/timeline_public_response_classification.h"

using namespace kivo::playback::timeline_public_response;

static void test_response_kind_enum_values() {
    assert(static_cast<uint8_t>(TimelinePublicResponseKind::Snapshot) == 0);
    assert(static_cast<uint8_t>(TimelinePublicResponseKind::Delta) == 1);
    assert(static_cast<uint8_t>(TimelinePublicResponseKind::Status) == 2);
    assert(static_cast<uint8_t>(TimelinePublicResponseKind::Unknown) == 3);
    std::cout << "PASS: test_response_kind_enum_values" << std::endl;
}

static void test_response_scope_enum_values() {
    assert(static_cast<uint8_t>(TimelinePublicResponseScope::Current) == 0);
    assert(static_cast<uint8_t>(TimelinePublicResponseScope::Since) == 1);
    assert(static_cast<uint8_t>(TimelinePublicResponseScope::Window) == 2);
    assert(static_cast<uint8_t>(TimelinePublicResponseScope::PublicSafe) == 3);
    assert(static_cast<uint8_t>(TimelinePublicResponseScope::Unknown) == 4);
    std::cout << "PASS: test_response_scope_enum_values" << std::endl;
}

void test_response_classification_default_construction() {
    test_response_kind_enum_values();
    test_response_scope_enum_values();

    TimelinePublicResponseClassification cls{};
    assert(cls.kind == TimelinePublicResponseKind::Unknown);
    assert(cls.scope == TimelinePublicResponseScope::Unknown);

    TimelinePublicResponseClassification cls2{
        .kind = TimelinePublicResponseKind::Snapshot,
        .scope = TimelinePublicResponseScope::Current
    };
    assert(cls2.kind == TimelinePublicResponseKind::Snapshot);
    assert(cls2.scope == TimelinePublicResponseScope::Current);
    assert(cls == cls);
    assert(!(cls == cls2));

    std::cout << "PASS: test_response_classification_default_construction" << std::endl;

    cls.kind = TimelinePublicResponseKind::Status;
    cls.scope = TimelinePublicResponseScope::Window;
    assert(cls.kind == TimelinePublicResponseKind::Status);
    assert(cls.scope == TimelinePublicResponseScope::Window);

    std::cout << "PASS: test_response_classification_field_modification" << std::endl;
}
