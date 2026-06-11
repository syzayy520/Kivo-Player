#include <cassert>
#include <iostream>

#include "playback/track_transition_public/identity/track_transition_public_identity.h"

using namespace kivo::playback::track_transition_public;

void test_track_transition_public_anchor_default_construction();
void test_track_transition_public_classification_default_construction();
void test_track_transition_public_transition_default_construction();
void test_track_transition_public_outcome_default_construction();
void test_track_transition_public_boundary_cross_family();

int main() {
    TrackTransitionPublicIdentity identity{};
    assert(identity.transition_id.value == 0);
    assert(identity.sequence_id.value == 0);
    assert(identity.generation.value == 0);
    test_track_transition_public_anchor_default_construction();
    test_track_transition_public_classification_default_construction();
    test_track_transition_public_transition_default_construction();
    test_track_transition_public_outcome_default_construction();
    test_track_transition_public_boundary_cross_family();
    std::cout << "track_transition_public tests passed" << std::endl;
    return 0;
}
