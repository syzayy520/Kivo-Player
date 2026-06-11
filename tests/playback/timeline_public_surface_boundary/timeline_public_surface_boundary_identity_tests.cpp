#include <cassert>
#include <iostream>

#include "playback/timeline_public_surface_boundary/identity/timeline_public_surface_boundary_identity.h"

using namespace kivo::playback::timeline_public_surface_boundary;

static void test_surface_boundary_id_default_construction() {
    TimelinePublicSurfaceBoundaryId id{};
    assert(id.value == 0);

    TimelinePublicSurfaceBoundaryId id2{42};
    assert(id2.value == 42);
    assert(id == id);
    assert(!(id == id2));

    std::cout << "PASS: test_surface_boundary_id_default_construction" << std::endl;
}

static void test_surface_boundary_sequence_id_default_construction() {
    TimelinePublicSurfaceBoundarySequenceId seq{};
    assert(seq.value == 0);

    TimelinePublicSurfaceBoundarySequenceId seq2{99};
    assert(seq2.value == 99);
    assert(seq == seq);
    assert(!(seq == seq2));

    std::cout << "PASS: test_surface_boundary_sequence_id_default_construction" << std::endl;
}

static void test_surface_boundary_generation_default_construction() {
    TimelinePublicSurfaceBoundaryGeneration gen{};
    assert(gen.value == 0);

    TimelinePublicSurfaceBoundaryGeneration gen2{7};
    assert(gen2.value == 7);
    assert(gen == gen);
    assert(!(gen == gen2));

    std::cout << "PASS: test_surface_boundary_generation_default_construction" << std::endl;
}

static void test_surface_boundary_identity_default_construction() {
    TimelinePublicSurfaceBoundaryIdentity identity{};
    assert(identity.boundary_id.value == 0);
    assert(identity.sequence_id.value == 0);
    assert(identity.generation.value == 0);

    TimelinePublicSurfaceBoundaryIdentity identity2{
        .boundary_id = TimelinePublicSurfaceBoundaryId{1},
        .sequence_id = TimelinePublicSurfaceBoundarySequenceId{2},
        .generation = TimelinePublicSurfaceBoundaryGeneration{3}
    };
    assert(identity2.boundary_id.value == 1);
    assert(identity2.sequence_id.value == 2);
    assert(identity2.generation.value == 3);
    assert(identity == identity);
    assert(!(identity == identity2));

    std::cout << "PASS: test_surface_boundary_identity_default_construction" << std::endl;
}

static void test_surface_boundary_identity_field_modification() {
    TimelinePublicSurfaceBoundaryIdentity identity{};
    identity.boundary_id = TimelinePublicSurfaceBoundaryId{100};
    identity.sequence_id = TimelinePublicSurfaceBoundarySequenceId{200};
    identity.generation = TimelinePublicSurfaceBoundaryGeneration{300};

    assert(identity.boundary_id.value == 100);
    assert(identity.sequence_id.value == 200);
    assert(identity.generation.value == 300);

    std::cout << "PASS: test_surface_boundary_identity_field_modification" << std::endl;
}

void test_surface_boundary_anchor_default_construction();
void test_surface_boundary_classification_default_construction();
void test_surface_boundary_boundary_default_construction();
void test_surface_boundary_outcome_default_construction();
void test_surface_boundary_contract_default_construction();

int main() {
    test_surface_boundary_id_default_construction();
    test_surface_boundary_sequence_id_default_construction();
    test_surface_boundary_generation_default_construction();
    test_surface_boundary_identity_default_construction();
    test_surface_boundary_identity_field_modification();
    test_surface_boundary_anchor_default_construction();
    test_surface_boundary_classification_default_construction();
    test_surface_boundary_boundary_default_construction();
    test_surface_boundary_outcome_default_construction();
    test_surface_boundary_contract_default_construction();
    std::cout << "All timeline_public_surface_boundary tests passed" << std::endl;
    return 0;
}
