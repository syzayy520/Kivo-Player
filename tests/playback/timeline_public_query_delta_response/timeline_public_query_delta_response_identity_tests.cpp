#include <cassert>
#include <iostream>

#include "playback/timeline_public_query_delta_response/identity/timeline_public_query_delta_response_identity.h"

using namespace kivo::playback::timeline_public_query_delta_response;

static void test_query_delta_response_key_default_construction() {
    TimelinePublicQueryDeltaResponseKey key{};
    assert(key.value == 0);

    TimelinePublicQueryDeltaResponseKey key2{42};
    assert(key2.value == 42);
    assert(key == key);
    assert(!(key == key2));

    std::cout << "PASS: test_query_delta_response_key_default_construction" << std::endl;
}

static void test_query_delta_response_sequence_default_construction() {
    TimelinePublicQueryDeltaResponseSequenceId sequence_id{};
    assert(sequence_id.value == 0);

    TimelinePublicQueryDeltaResponseSequenceId sequence_id2{84};
    assert(sequence_id2.value == 84);
    assert(sequence_id == sequence_id);
    assert(!(sequence_id == sequence_id2));

    std::cout << "PASS: test_query_delta_response_sequence_default_construction" << std::endl;
}

static void test_query_delta_response_generation_default_construction() {
    TimelinePublicQueryDeltaResponseGeneration generation{};
    assert(generation.value == 0);

    TimelinePublicQueryDeltaResponseGeneration generation2{7};
    assert(generation2.value == 7);
    assert(generation == generation);
    assert(!(generation == generation2));

    std::cout << "PASS: test_query_delta_response_generation_default_construction" << std::endl;
}

static void test_query_delta_response_identity_default_construction() {
    TimelinePublicQueryDeltaResponseIdentity identity{};
    assert(identity.query_delta_response_key.value == 0);
    assert(identity.sequence_id.value == 0);
    assert(identity.generation.value == 0);

    TimelinePublicQueryDeltaResponseIdentity identity2{
        .query_delta_response_key = TimelinePublicQueryDeltaResponseKey{1},
        .sequence_id = TimelinePublicQueryDeltaResponseSequenceId{2},
        .generation = TimelinePublicQueryDeltaResponseGeneration{3}
    };
    assert(identity2.query_delta_response_key.value == 1);
    assert(identity2.sequence_id.value == 2);
    assert(identity2.generation.value == 3);
    assert(identity == identity);
    assert(!(identity == identity2));

    std::cout << "PASS: test_query_delta_response_identity_default_construction" << std::endl;
}

void test_query_delta_response_anchor_default_construction();
void test_query_delta_response_classification_default_construction();
void test_query_delta_response_binding_default_construction();
void test_query_delta_response_outcome_default_construction();
void test_query_delta_response_boundary_compile_surface();

int main() {
    test_query_delta_response_key_default_construction();
    test_query_delta_response_sequence_default_construction();
    test_query_delta_response_generation_default_construction();
    test_query_delta_response_identity_default_construction();
    test_query_delta_response_anchor_default_construction();
    test_query_delta_response_classification_default_construction();
    test_query_delta_response_binding_default_construction();
    test_query_delta_response_outcome_default_construction();
    test_query_delta_response_boundary_compile_surface();
    std::cout << "All timeline_public_query_delta_response tests passed" << std::endl;
    return 0;
}
