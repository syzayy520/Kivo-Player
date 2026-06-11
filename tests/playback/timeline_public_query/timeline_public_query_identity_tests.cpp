#include <cassert>
#include <iostream>

#include "playback/timeline_public_query/identity/timeline_public_query_identity.h"

using namespace kivo::playback::timeline_public_query;

static void test_query_id_default_construction() {
    TimelinePublicQueryId id{};
    assert(id.value == 0);

    TimelinePublicQueryId id2{42};
    assert(id2.value == 42);
    assert(id == id);
    assert(!(id == id2));

    std::cout << "PASS: test_query_id_default_construction" << std::endl;
}

static void test_query_sequence_id_default_construction() {
    TimelinePublicQuerySequenceId seq{};
    assert(seq.value == 0);

    TimelinePublicQuerySequenceId seq2{99};
    assert(seq2.value == 99);
    assert(seq == seq);
    assert(!(seq == seq2));

    std::cout << "PASS: test_query_sequence_id_default_construction" << std::endl;
}

static void test_query_generation_default_construction() {
    TimelinePublicQueryGeneration gen{};
    assert(gen.value == 0);

    TimelinePublicQueryGeneration gen2{7};
    assert(gen2.value == 7);
    assert(gen == gen);
    assert(!(gen == gen2));

    std::cout << "PASS: test_query_generation_default_construction" << std::endl;
}

static void test_query_identity_default_construction() {
    TimelinePublicQueryIdentity identity{};
    assert(identity.query_id.value == 0);
    assert(identity.sequence_id.value == 0);
    assert(identity.generation.value == 0);

    TimelinePublicQueryIdentity identity2{
        .query_id = TimelinePublicQueryId{1},
        .sequence_id = TimelinePublicQuerySequenceId{2},
        .generation = TimelinePublicQueryGeneration{3}
    };
    assert(identity2.query_id.value == 1);
    assert(identity2.sequence_id.value == 2);
    assert(identity2.generation.value == 3);

    assert(identity == identity);
    assert(!(identity == identity2));

    std::cout << "PASS: test_query_identity_default_construction" << std::endl;
}

static void test_query_identity_field_modification() {
    TimelinePublicQueryIdentity identity{};
    identity.query_id = TimelinePublicQueryId{100};
    identity.sequence_id = TimelinePublicQuerySequenceId{200};
    identity.generation = TimelinePublicQueryGeneration{300};

    assert(identity.query_id.value == 100);
    assert(identity.sequence_id.value == 200);
    assert(identity.generation.value == 300);

    std::cout << "PASS: test_query_identity_field_modification" << std::endl;
}

void test_query_anchor_default_construction();
void test_query_classification_default_construction();
void test_query_query_default_construction();
void test_query_outcome_default_construction();
void test_query_boundary_cross_family();

int main() {
    test_query_id_default_construction();
    test_query_sequence_id_default_construction();
    test_query_generation_default_construction();
    test_query_identity_default_construction();
    test_query_identity_field_modification();
    test_query_anchor_default_construction();
    test_query_classification_default_construction();
    test_query_query_default_construction();
    test_query_outcome_default_construction();
    test_query_boundary_cross_family();
    std::cout << "All timeline_public_query tests passed" << std::endl;
    return 0;
}
