#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/lifecycle_phase/classification/playback_lifecycle_phase_classification.h"

using namespace kivo::playback::lifecycle_phase;

static void test_lifecycle_phase_kind_enum_values() {
    assert(static_cast<std::uint8_t>(PlaybackLifecyclePhaseKind::Created) == 0);
    assert(static_cast<std::uint8_t>(PlaybackLifecyclePhaseKind::Opened) == 1);
    assert(static_cast<std::uint8_t>(PlaybackLifecyclePhaseKind::Active) == 2);
    assert(static_cast<std::uint8_t>(PlaybackLifecyclePhaseKind::Inactive) == 3);
    assert(static_cast<std::uint8_t>(PlaybackLifecyclePhaseKind::Closed) == 4);
    assert(static_cast<std::uint8_t>(PlaybackLifecyclePhaseKind::Unknown) == 5);
    std::cout << "PASS: test_lifecycle_phase_kind_enum_values" << std::endl;
}

static void test_lifecycle_phase_scope_enum_values() {
    assert(static_cast<std::uint8_t>(PlaybackLifecyclePhaseScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(PlaybackLifecyclePhaseScope::Session) == 1);
    assert(static_cast<std::uint8_t>(PlaybackLifecyclePhaseScope::Timeline) == 2);
    assert(static_cast<std::uint8_t>(PlaybackLifecyclePhaseScope::Unknown) == 3);
    std::cout << "PASS: test_lifecycle_phase_scope_enum_values" << std::endl;
}

void test_lifecycle_phase_classification_default_construction() {
    test_lifecycle_phase_kind_enum_values();
    test_lifecycle_phase_scope_enum_values();

    PlaybackLifecyclePhaseClassification cls{};
    assert(cls.kind == PlaybackLifecyclePhaseKind::Unknown);
    assert(cls.scope == PlaybackLifecyclePhaseScope::Unknown);

    PlaybackLifecyclePhaseClassification cls2{
        .kind = PlaybackLifecyclePhaseKind::Created,
        .scope = PlaybackLifecyclePhaseScope::PublicSurface
    };
    assert(cls2.kind == PlaybackLifecyclePhaseKind::Created);
    assert(cls2.scope == PlaybackLifecyclePhaseScope::PublicSurface);
    assert(cls == cls);
    assert(!(cls == cls2));

    std::cout << "PASS: test_lifecycle_phase_classification_default_construction" << std::endl;

    cls.kind = PlaybackLifecyclePhaseKind::Active;
    cls.scope = PlaybackLifecyclePhaseScope::Timeline;
    assert(cls.kind == PlaybackLifecyclePhaseKind::Active);
    assert(cls.scope == PlaybackLifecyclePhaseScope::Timeline);

    std::cout << "PASS: test_lifecycle_phase_classification_field_modification" << std::endl;
}
