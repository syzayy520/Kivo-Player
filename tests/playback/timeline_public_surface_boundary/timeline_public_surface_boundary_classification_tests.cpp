#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/timeline_public_surface_boundary/classification/timeline_public_surface_boundary_classification.h"

using namespace kivo::playback::timeline_public_surface_boundary;

static void test_surface_boundary_kind_enum_values() {
    assert(static_cast<std::uint8_t>(TimelinePublicSurfaceBoundaryKind::Query) == 0);
    assert(static_cast<std::uint8_t>(TimelinePublicSurfaceBoundaryKind::Response) == 1);
    assert(static_cast<std::uint8_t>(TimelinePublicSurfaceBoundaryKind::Surface) == 2);
    assert(static_cast<std::uint8_t>(TimelinePublicSurfaceBoundaryKind::Unknown) == 3);
    std::cout << "PASS: test_surface_boundary_kind_enum_values" << std::endl;
}

static void test_surface_boundary_scope_enum_values() {
    assert(static_cast<std::uint8_t>(TimelinePublicSurfaceBoundaryScope::PublicSafe) == 0);
    assert(static_cast<std::uint8_t>(TimelinePublicSurfaceBoundaryScope::BoundaryOnly) == 1);
    assert(static_cast<std::uint8_t>(TimelinePublicSurfaceBoundaryScope::TimelineOnly) == 2);
    assert(static_cast<std::uint8_t>(TimelinePublicSurfaceBoundaryScope::Unknown) == 3);
    std::cout << "PASS: test_surface_boundary_scope_enum_values" << std::endl;
}

void test_surface_boundary_classification_default_construction() {
    test_surface_boundary_kind_enum_values();
    test_surface_boundary_scope_enum_values();

    TimelinePublicSurfaceBoundaryClassification cls{};
    assert(cls.kind == TimelinePublicSurfaceBoundaryKind::Unknown);
    assert(cls.scope == TimelinePublicSurfaceBoundaryScope::Unknown);

    TimelinePublicSurfaceBoundaryClassification cls2{
        .kind = TimelinePublicSurfaceBoundaryKind::Surface,
        .scope = TimelinePublicSurfaceBoundaryScope::PublicSafe
    };
    assert(cls2.kind == TimelinePublicSurfaceBoundaryKind::Surface);
    assert(cls2.scope == TimelinePublicSurfaceBoundaryScope::PublicSafe);
    assert(cls == cls);
    assert(!(cls == cls2));

    std::cout << "PASS: test_surface_boundary_classification_default_construction" << std::endl;

    cls.kind = TimelinePublicSurfaceBoundaryKind::Response;
    cls.scope = TimelinePublicSurfaceBoundaryScope::BoundaryOnly;
    assert(cls.kind == TimelinePublicSurfaceBoundaryKind::Response);
    assert(cls.scope == TimelinePublicSurfaceBoundaryScope::BoundaryOnly);

    std::cout << "PASS: test_surface_boundary_classification_field_modification" << std::endl;
}
