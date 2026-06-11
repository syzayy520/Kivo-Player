#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/session_public/classification/playback_session_public_classification.h"

using namespace kivo::playback::session_public;

static void test_session_public_kind_enum_values() {
    assert(static_cast<std::uint8_t>(PlaybackSessionPublicKind::Created) == 0);
    assert(static_cast<std::uint8_t>(PlaybackSessionPublicKind::Bound) == 1);
    assert(static_cast<std::uint8_t>(PlaybackSessionPublicKind::Active) == 2);
    assert(static_cast<std::uint8_t>(PlaybackSessionPublicKind::Released) == 3);
    assert(static_cast<std::uint8_t>(PlaybackSessionPublicKind::Unknown) == 4);
    std::cout << "PASS: test_session_public_kind_enum_values" << std::endl;
}

static void test_session_public_scope_enum_values() {
    assert(static_cast<std::uint8_t>(PlaybackSessionPublicScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(PlaybackSessionPublicScope::Lifecycle) == 1);
    assert(static_cast<std::uint8_t>(PlaybackSessionPublicScope::Session) == 2);
    assert(static_cast<std::uint8_t>(PlaybackSessionPublicScope::Unknown) == 3);
    std::cout << "PASS: test_session_public_scope_enum_values" << std::endl;
}

void test_session_public_classification_default_construction() {
    test_session_public_kind_enum_values();
    test_session_public_scope_enum_values();

    PlaybackSessionPublicClassification cls{};
    assert(cls.kind == PlaybackSessionPublicKind::Unknown);
    assert(cls.scope == PlaybackSessionPublicScope::Unknown);

    PlaybackSessionPublicClassification cls2{
        .kind = PlaybackSessionPublicKind::Created,
        .scope = PlaybackSessionPublicScope::PublicSurface
    };
    assert(cls2.kind == PlaybackSessionPublicKind::Created);
    assert(cls2.scope == PlaybackSessionPublicScope::PublicSurface);
    assert(cls == cls);
    assert(!(cls == cls2));

    std::cout << "PASS: test_session_public_classification_default_construction" << std::endl;

    cls.kind = PlaybackSessionPublicKind::Active;
    cls.scope = PlaybackSessionPublicScope::Session;
    assert(cls.kind == PlaybackSessionPublicKind::Active);
    assert(cls.scope == PlaybackSessionPublicScope::Session);

    std::cout << "PASS: test_session_public_classification_field_modification" << std::endl;
}
