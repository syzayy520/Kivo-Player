#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/stream_selection_public/classification/stream_selection_public_classification.h"

using namespace kivo::playback::stream_selection_public;

static void test_stream_selection_public_kind_enum_values() {
    assert(static_cast<std::uint8_t>(StreamSelectionPublicKind::Video) == 0);
    assert(static_cast<std::uint8_t>(StreamSelectionPublicKind::Audio) == 1);
    assert(static_cast<std::uint8_t>(StreamSelectionPublicKind::Subtitle) == 2);
    assert(static_cast<std::uint8_t>(StreamSelectionPublicKind::Unknown) == 3);
    std::cout << "PASS: test_stream_selection_public_kind_enum_values" << std::endl;
}

static void test_stream_selection_public_scope_enum_values() {
    assert(static_cast<std::uint8_t>(StreamSelectionPublicScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(StreamSelectionPublicScope::Media) == 1);
    assert(static_cast<std::uint8_t>(StreamSelectionPublicScope::Selection) == 2);
    assert(static_cast<std::uint8_t>(StreamSelectionPublicScope::Unknown) == 3);
    std::cout << "PASS: test_stream_selection_public_scope_enum_values" << std::endl;
}

void test_stream_selection_public_classification_default_construction() {
    test_stream_selection_public_kind_enum_values();
    test_stream_selection_public_scope_enum_values();
    StreamSelectionPublicClassification cls{};
    assert(cls.kind == StreamSelectionPublicKind::Unknown);
    assert(cls.scope == StreamSelectionPublicScope::Unknown);
    StreamSelectionPublicClassification cls2{
        .kind = StreamSelectionPublicKind::Video,
        .scope = StreamSelectionPublicScope::PublicSurface
    };
    assert(cls2.kind == StreamSelectionPublicKind::Video);
    assert(cls2.scope == StreamSelectionPublicScope::PublicSurface);
    assert(cls == cls);
    assert(!(cls == cls2));
    std::cout << "PASS: test_stream_selection_public_classification_default_construction" << std::endl;
    cls.kind = StreamSelectionPublicKind::Audio;
    cls.scope = StreamSelectionPublicScope::Selection;
    assert(cls.kind == StreamSelectionPublicKind::Audio);
    assert(cls.scope == StreamSelectionPublicScope::Selection);
    std::cout << "PASS: test_stream_selection_public_classification_field_modification" << std::endl;
}
