#include <cassert>
#include <iostream>

#include "playback/stream_selection_public/identity/stream_selection_public_identity.h"

using namespace kivo::playback::stream_selection_public;

static void test_stream_selection_public_id_default_construction() {
    StreamSelectionPublicId id{};
    assert(id.value == 0);
    StreamSelectionPublicId id2{42};
    assert(id2.value == 42);
    assert(id == id);
    assert(!(id == id2));
    std::cout << "PASS: test_stream_selection_public_id_default_construction" << std::endl;
}

static void test_stream_selection_public_sequence_id_default_construction() {
    StreamSelectionPublicSequenceId seq{};
    assert(seq.value == 0);
    StreamSelectionPublicSequenceId seq2{99};
    assert(seq2.value == 99);
    assert(seq == seq);
    assert(!(seq == seq2));
    std::cout << "PASS: test_stream_selection_public_sequence_id_default_construction" << std::endl;
}

static void test_stream_selection_public_generation_default_construction() {
    StreamSelectionPublicGeneration gen{};
    assert(gen.value == 0);
    StreamSelectionPublicGeneration gen2{7};
    assert(gen2.value == 7);
    assert(gen == gen);
    assert(!(gen == gen2));
    std::cout << "PASS: test_stream_selection_public_generation_default_construction" << std::endl;
}

static void test_stream_selection_public_identity_default_construction() {
    StreamSelectionPublicIdentity identity{};
    assert(identity.selection_id.value == 0);
    assert(identity.sequence_id.value == 0);
    assert(identity.generation.value == 0);
    StreamSelectionPublicIdentity identity2{
        .selection_id = StreamSelectionPublicId{1},
        .sequence_id = StreamSelectionPublicSequenceId{2},
        .generation = StreamSelectionPublicGeneration{3}
    };
    assert(identity2.selection_id.value == 1);
    assert(identity2.sequence_id.value == 2);
    assert(identity2.generation.value == 3);
    assert(identity == identity);
    assert(!(identity == identity2));
    std::cout << "PASS: test_stream_selection_public_identity_default_construction" << std::endl;
}

static void test_stream_selection_public_identity_field_modification() {
    StreamSelectionPublicIdentity identity{};
    identity.selection_id = StreamSelectionPublicId{100};
    identity.sequence_id = StreamSelectionPublicSequenceId{200};
    identity.generation = StreamSelectionPublicGeneration{300};
    assert(identity.selection_id.value == 100);
    assert(identity.sequence_id.value == 200);
    assert(identity.generation.value == 300);
    std::cout << "PASS: test_stream_selection_public_identity_field_modification" << std::endl;
}

void test_stream_selection_public_anchor_default_construction();
void test_stream_selection_public_classification_default_construction();
void test_stream_selection_public_selection_default_construction();
void test_stream_selection_public_outcome_default_construction();
void test_stream_selection_public_boundary_cross_family();

int main() {
    test_stream_selection_public_id_default_construction();
    test_stream_selection_public_sequence_id_default_construction();
    test_stream_selection_public_generation_default_construction();
    test_stream_selection_public_identity_default_construction();
    test_stream_selection_public_identity_field_modification();
    test_stream_selection_public_anchor_default_construction();
    test_stream_selection_public_classification_default_construction();
    test_stream_selection_public_selection_default_construction();
    test_stream_selection_public_outcome_default_construction();
    test_stream_selection_public_boundary_cross_family();
    std::cout << "All stream_selection_public tests passed" << std::endl;
    return 0;
}
