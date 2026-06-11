#include <cassert>
#include <iostream>

#include "playback/media_open_public/identity/media_open_public_identity.h"

using namespace kivo::playback::media_open_public;

static void test_media_open_public_id_default_construction() {
    MediaOpenPublicId id{};
    assert(id.value == 0);

    MediaOpenPublicId id2{42};
    assert(id2.value == 42);
    assert(id == id);
    assert(!(id == id2));

    std::cout << "PASS: test_media_open_public_id_default_construction" << std::endl;
}

static void test_media_open_public_sequence_id_default_construction() {
    MediaOpenPublicSequenceId seq{};
    assert(seq.value == 0);

    MediaOpenPublicSequenceId seq2{99};
    assert(seq2.value == 99);
    assert(seq == seq);
    assert(!(seq == seq2));

    std::cout << "PASS: test_media_open_public_sequence_id_default_construction" << std::endl;
}

static void test_media_open_public_generation_default_construction() {
    MediaOpenPublicGeneration gen{};
    assert(gen.value == 0);

    MediaOpenPublicGeneration gen2{7};
    assert(gen2.value == 7);
    assert(gen == gen);
    assert(!(gen == gen2));

    std::cout << "PASS: test_media_open_public_generation_default_construction" << std::endl;
}

static void test_media_open_public_identity_default_construction() {
    MediaOpenPublicIdentity identity{};
    assert(identity.open_id.value == 0);
    assert(identity.sequence_id.value == 0);
    assert(identity.generation.value == 0);

    MediaOpenPublicIdentity identity2{
        .open_id = MediaOpenPublicId{1},
        .sequence_id = MediaOpenPublicSequenceId{2},
        .generation = MediaOpenPublicGeneration{3}
    };
    assert(identity2.open_id.value == 1);
    assert(identity2.sequence_id.value == 2);
    assert(identity2.generation.value == 3);
    assert(identity == identity);
    assert(!(identity == identity2));

    std::cout << "PASS: test_media_open_public_identity_default_construction" << std::endl;
}

static void test_media_open_public_identity_field_modification() {
    MediaOpenPublicIdentity identity{};
    identity.open_id = MediaOpenPublicId{100};
    identity.sequence_id = MediaOpenPublicSequenceId{200};
    identity.generation = MediaOpenPublicGeneration{300};

    assert(identity.open_id.value == 100);
    assert(identity.sequence_id.value == 200);
    assert(identity.generation.value == 300);

    std::cout << "PASS: test_media_open_public_identity_field_modification" << std::endl;
}

void test_media_open_public_anchor_default_construction();
void test_media_open_public_classification_default_construction();
void test_media_open_public_open_default_construction();
void test_media_open_public_outcome_default_construction();
void test_media_open_public_boundary_cross_family();

int main() {
    test_media_open_public_id_default_construction();
    test_media_open_public_sequence_id_default_construction();
    test_media_open_public_generation_default_construction();
    test_media_open_public_identity_default_construction();
    test_media_open_public_identity_field_modification();
    test_media_open_public_anchor_default_construction();
    test_media_open_public_classification_default_construction();
    test_media_open_public_open_default_construction();
    test_media_open_public_outcome_default_construction();
    test_media_open_public_boundary_cross_family();
    std::cout << "All media_open_public tests passed" << std::endl;
    return 0;
}
