#include <cassert>
#include <iostream>

#include "playback/lifecycle_phase/identity/playback_lifecycle_phase_identity.h"

using namespace kivo::playback::lifecycle_phase;

static void test_lifecycle_phase_id_default_construction() {
    PlaybackLifecyclePhaseId id{};
    assert(id.value == 0);

    PlaybackLifecyclePhaseId id2{42};
    assert(id2.value == 42);
    assert(id == id);
    assert(!(id == id2));

    std::cout << "PASS: test_lifecycle_phase_id_default_construction" << std::endl;
}

static void test_lifecycle_phase_sequence_id_default_construction() {
    PlaybackLifecyclePhaseSequenceId seq{};
    assert(seq.value == 0);

    PlaybackLifecyclePhaseSequenceId seq2{99};
    assert(seq2.value == 99);
    assert(seq == seq);
    assert(!(seq == seq2));

    std::cout << "PASS: test_lifecycle_phase_sequence_id_default_construction" << std::endl;
}

static void test_lifecycle_phase_generation_default_construction() {
    PlaybackLifecyclePhaseGeneration gen{};
    assert(gen.value == 0);

    PlaybackLifecyclePhaseGeneration gen2{7};
    assert(gen2.value == 7);
    assert(gen == gen);
    assert(!(gen == gen2));

    std::cout << "PASS: test_lifecycle_phase_generation_default_construction" << std::endl;
}

static void test_lifecycle_phase_identity_default_construction() {
    PlaybackLifecyclePhaseIdentity identity{};
    assert(identity.phase_id.value == 0);
    assert(identity.sequence_id.value == 0);
    assert(identity.generation.value == 0);

    PlaybackLifecyclePhaseIdentity identity2{
        .phase_id = PlaybackLifecyclePhaseId{1},
        .sequence_id = PlaybackLifecyclePhaseSequenceId{2},
        .generation = PlaybackLifecyclePhaseGeneration{3}
    };
    assert(identity2.phase_id.value == 1);
    assert(identity2.sequence_id.value == 2);
    assert(identity2.generation.value == 3);
    assert(identity == identity);
    assert(!(identity == identity2));

    std::cout << "PASS: test_lifecycle_phase_identity_default_construction" << std::endl;
}

static void test_lifecycle_phase_identity_field_modification() {
    PlaybackLifecyclePhaseIdentity identity{};
    identity.phase_id = PlaybackLifecyclePhaseId{100};
    identity.sequence_id = PlaybackLifecyclePhaseSequenceId{200};
    identity.generation = PlaybackLifecyclePhaseGeneration{300};

    assert(identity.phase_id.value == 100);
    assert(identity.sequence_id.value == 200);
    assert(identity.generation.value == 300);

    std::cout << "PASS: test_lifecycle_phase_identity_field_modification" << std::endl;
}

void test_lifecycle_phase_anchor_default_construction();
void test_lifecycle_phase_classification_default_construction();
void test_lifecycle_phase_phase_default_construction();
void test_lifecycle_phase_outcome_default_construction();
void test_lifecycle_phase_boundary_cross_family();

int main() {
    test_lifecycle_phase_id_default_construction();
    test_lifecycle_phase_sequence_id_default_construction();
    test_lifecycle_phase_generation_default_construction();
    test_lifecycle_phase_identity_default_construction();
    test_lifecycle_phase_identity_field_modification();
    test_lifecycle_phase_anchor_default_construction();
    test_lifecycle_phase_classification_default_construction();
    test_lifecycle_phase_phase_default_construction();
    test_lifecycle_phase_outcome_default_construction();
    test_lifecycle_phase_boundary_cross_family();
    std::cout << "All lifecycle_phase tests passed" << std::endl;
    return 0;
}
