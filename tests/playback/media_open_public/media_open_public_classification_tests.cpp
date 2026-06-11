#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/media_open_public/classification/media_open_public_classification.h"

using namespace kivo::playback::media_open_public;

static void test_media_open_public_kind_enum_values() {
    assert(static_cast<std::uint8_t>(MediaOpenPublicKind::Local) == 0);
    assert(static_cast<std::uint8_t>(MediaOpenPublicKind::External) == 1);
    assert(static_cast<std::uint8_t>(MediaOpenPublicKind::Resume) == 2);
    assert(static_cast<std::uint8_t>(MediaOpenPublicKind::Unknown) == 3);
    std::cout << "PASS: test_media_open_public_kind_enum_values" << std::endl;
}

static void test_media_open_public_scope_enum_values() {
    assert(static_cast<std::uint8_t>(MediaOpenPublicScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(MediaOpenPublicScope::Session) == 1);
    assert(static_cast<std::uint8_t>(MediaOpenPublicScope::Media) == 2);
    assert(static_cast<std::uint8_t>(MediaOpenPublicScope::Unknown) == 3);
    std::cout << "PASS: test_media_open_public_scope_enum_values" << std::endl;
}

void test_media_open_public_classification_default_construction() {
    test_media_open_public_kind_enum_values();
    test_media_open_public_scope_enum_values();

    MediaOpenPublicClassification cls{};
    assert(cls.kind == MediaOpenPublicKind::Unknown);
    assert(cls.scope == MediaOpenPublicScope::Unknown);

    MediaOpenPublicClassification cls2{
        .kind = MediaOpenPublicKind::Local,
        .scope = MediaOpenPublicScope::PublicSurface
    };
    assert(cls2.kind == MediaOpenPublicKind::Local);
    assert(cls2.scope == MediaOpenPublicScope::PublicSurface);
    assert(cls == cls);
    assert(!(cls == cls2));

    std::cout << "PASS: test_media_open_public_classification_default_construction" << std::endl;

    cls.kind = MediaOpenPublicKind::Resume;
    cls.scope = MediaOpenPublicScope::Media;
    assert(cls.kind == MediaOpenPublicKind::Resume);
    assert(cls.scope == MediaOpenPublicScope::Media);

    std::cout << "PASS: test_media_open_public_classification_field_modification" << std::endl;
}
