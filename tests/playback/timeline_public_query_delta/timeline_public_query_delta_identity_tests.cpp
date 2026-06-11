#include <cassert>
#include <iostream>

#include "playback/timeline_public_query_delta/identity/timeline_public_query_delta_identity.h"

using namespace kivo::playback::timeline_public_query_delta;

static void test_query_delta_id_default_construction() {
    TimelinePublicQueryDeltaId id{};
    assert(id.value == 0);

    TimelinePublicQueryDeltaId id2{42};
    assert(id2.value == 42);
    assert(id == id);
    assert(!(id == id2));

    std::cout << "PASS: test_query_delta_id_default_construction" << std::endl;
}

static void test_query_delta_sequence_id_default_construction() {
    TimelinePublicQueryDeltaSequenceId sequence_id{};
    assert(sequence_id.value == 0);

    TimelinePublicQueryDeltaSequenceId sequence_id2{84};
    assert(sequence_id2.value == 84);
    assert(sequence_id == sequence_id);
    assert(!(sequence_id == sequence_id2));

    std::cout << "PASS: test_query_delta_sequence_id_default_construction" << std::endl;
}

static void test_query_delta_generation_default_construction() {
    TimelinePublicQueryDeltaGeneration generation{};
    assert(generation.value == 0);

    TimelinePublicQueryDeltaGeneration generation2{7};
    assert(generation2.value == 7);
    assert(generation == generation);
    assert(!(generation == generation2));

    std::cout << "PASS: test_query_delta_generation_default_construction" << std::endl;
}

static void test_query_delta_identity_default_construction() {
    TimelinePublicQueryDeltaIdentity identity{};
    assert(identity.query_delta_id.value == 0);
    assert(identity.sequence_id.value == 0);
    assert(identity.generation.value == 0);

    TimelinePublicQueryDeltaIdentity identity2{
        .query_delta_id = TimelinePublicQueryDeltaId{1},
        .sequence_id = TimelinePublicQueryDeltaSequenceId{2},
        .generation = TimelinePublicQueryDeltaGeneration{3}
    };
    assert(identity2.query_delta_id.value == 1);
    assert(identity2.sequence_id.value == 2);
    assert(identity2.generation.value == 3);
    assert(identity == identity);
    assert(!(identity == identity2));

    std::cout << "PASS: test_query_delta_identity_default_construction" << std::endl;
}

void test_timeline_public_query_delta_anchor_default_construction();
void test_timeline_public_query_delta_classification_default_construction();
void test_timeline_public_query_delta_query_delta_default_construction();
void test_timeline_public_query_delta_outcome_default_construction();
void test_timeline_public_query_delta_boundary_compile_surface();

int main() {
    test_query_delta_id_default_construction();
    test_query_delta_sequence_id_default_construction();
    test_query_delta_generation_default_construction();
    test_query_delta_identity_default_construction();
    test_timeline_public_query_delta_anchor_default_construction();
    test_timeline_public_query_delta_classification_default_construction();
    test_timeline_public_query_delta_query_delta_default_construction();
    test_timeline_public_query_delta_outcome_default_construction();
    test_timeline_public_query_delta_boundary_compile_surface();
    std::cout << "All timeline_public_query_delta tests passed" << std::endl;
    return 0;
}
