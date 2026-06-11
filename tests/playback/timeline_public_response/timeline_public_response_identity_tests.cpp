#include <cassert>
#include <iostream>

#include "playback/timeline_public_response/identity/timeline_public_response_identity.h"

using namespace kivo::playback::timeline_public_response;

static void test_response_id_default_construction() {
    TimelinePublicResponseId id{};
    assert(id.value == 0);

    TimelinePublicResponseId id2{42};
    assert(id2.value == 42);
    assert(id == id);
    assert(!(id == id2));

    std::cout << "PASS: test_response_id_default_construction" << std::endl;
}

static void test_response_sequence_id_default_construction() {
    TimelinePublicResponseSequenceId seq{};
    assert(seq.value == 0);

    TimelinePublicResponseSequenceId seq2{99};
    assert(seq2.value == 99);
    assert(seq == seq);
    assert(!(seq == seq2));

    std::cout << "PASS: test_response_sequence_id_default_construction" << std::endl;
}

static void test_response_generation_default_construction() {
    TimelinePublicResponseGeneration gen{};
    assert(gen.value == 0);

    TimelinePublicResponseGeneration gen2{7};
    assert(gen2.value == 7);
    assert(gen == gen);
    assert(!(gen == gen2));

    std::cout << "PASS: test_response_generation_default_construction" << std::endl;
}

static void test_response_identity_default_construction() {
    TimelinePublicResponseIdentity identity{};
    assert(identity.response_id.value == 0);
    assert(identity.sequence_id.value == 0);
    assert(identity.generation.value == 0);

    TimelinePublicResponseIdentity identity2{
        .response_id = TimelinePublicResponseId{1},
        .sequence_id = TimelinePublicResponseSequenceId{2},
        .generation = TimelinePublicResponseGeneration{3}
    };
    assert(identity2.response_id.value == 1);
    assert(identity2.sequence_id.value == 2);
    assert(identity2.generation.value == 3);
    assert(identity == identity);
    assert(!(identity == identity2));

    std::cout << "PASS: test_response_identity_default_construction" << std::endl;
}

static void test_response_identity_field_modification() {
    TimelinePublicResponseIdentity identity{};
    identity.response_id = TimelinePublicResponseId{100};
    identity.sequence_id = TimelinePublicResponseSequenceId{200};
    identity.generation = TimelinePublicResponseGeneration{300};

    assert(identity.response_id.value == 100);
    assert(identity.sequence_id.value == 200);
    assert(identity.generation.value == 300);

    std::cout << "PASS: test_response_identity_field_modification" << std::endl;
}

void test_response_anchor_default_construction();
void test_response_classification_default_construction();
void test_response_response_default_construction();
void test_response_outcome_default_construction();
void test_response_boundary_cross_family();

int main() {
    test_response_id_default_construction();
    test_response_sequence_id_default_construction();
    test_response_generation_default_construction();
    test_response_identity_default_construction();
    test_response_identity_field_modification();
    test_response_anchor_default_construction();
    test_response_classification_default_construction();
    test_response_response_default_construction();
    test_response_outcome_default_construction();
    test_response_boundary_cross_family();
    std::cout << "All timeline_public_response tests passed" << std::endl;
    return 0;
}
