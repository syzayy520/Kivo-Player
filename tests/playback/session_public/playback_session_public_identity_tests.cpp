#include <cassert>
#include <iostream>

#include "playback/session_public/identity/playback_session_public_identity.h"

using namespace kivo::playback::session_public;

static void test_session_public_id_default_construction() {
    PlaybackSessionPublicId id{};
    assert(id.value == 0);

    PlaybackSessionPublicId id2{42};
    assert(id2.value == 42);
    assert(id == id);
    assert(!(id == id2));

    std::cout << "PASS: test_session_public_id_default_construction" << std::endl;
}

static void test_session_public_sequence_id_default_construction() {
    PlaybackSessionPublicSequenceId seq{};
    assert(seq.value == 0);

    PlaybackSessionPublicSequenceId seq2{99};
    assert(seq2.value == 99);
    assert(seq == seq);
    assert(!(seq == seq2));

    std::cout << "PASS: test_session_public_sequence_id_default_construction" << std::endl;
}

static void test_session_public_generation_default_construction() {
    PlaybackSessionPublicGeneration gen{};
    assert(gen.value == 0);

    PlaybackSessionPublicGeneration gen2{7};
    assert(gen2.value == 7);
    assert(gen == gen);
    assert(!(gen == gen2));

    std::cout << "PASS: test_session_public_generation_default_construction" << std::endl;
}

static void test_session_public_identity_default_construction() {
    PlaybackSessionPublicIdentity identity{};
    assert(identity.session_id.value == 0);
    assert(identity.sequence_id.value == 0);
    assert(identity.generation.value == 0);

    PlaybackSessionPublicIdentity identity2{
        .session_id = PlaybackSessionPublicId{1},
        .sequence_id = PlaybackSessionPublicSequenceId{2},
        .generation = PlaybackSessionPublicGeneration{3}
    };
    assert(identity2.session_id.value == 1);
    assert(identity2.sequence_id.value == 2);
    assert(identity2.generation.value == 3);
    assert(identity == identity);
    assert(!(identity == identity2));

    std::cout << "PASS: test_session_public_identity_default_construction" << std::endl;
}

static void test_session_public_identity_field_modification() {
    PlaybackSessionPublicIdentity identity{};
    identity.session_id = PlaybackSessionPublicId{100};
    identity.sequence_id = PlaybackSessionPublicSequenceId{200};
    identity.generation = PlaybackSessionPublicGeneration{300};

    assert(identity.session_id.value == 100);
    assert(identity.sequence_id.value == 200);
    assert(identity.generation.value == 300);

    std::cout << "PASS: test_session_public_identity_field_modification" << std::endl;
}

void test_session_public_anchor_default_construction();
void test_session_public_classification_default_construction();
void test_session_public_session_default_construction();
void test_session_public_outcome_default_construction();
void test_session_public_boundary_cross_family();

int main() {
    test_session_public_id_default_construction();
    test_session_public_sequence_id_default_construction();
    test_session_public_generation_default_construction();
    test_session_public_identity_default_construction();
    test_session_public_identity_field_modification();
    test_session_public_anchor_default_construction();
    test_session_public_classification_default_construction();
    test_session_public_session_default_construction();
    test_session_public_outcome_default_construction();
    test_session_public_boundary_cross_family();
    std::cout << "All session_public tests passed" << std::endl;
    return 0;
}
