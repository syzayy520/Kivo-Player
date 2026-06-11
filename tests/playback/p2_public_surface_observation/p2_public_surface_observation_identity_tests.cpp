#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_observation/identity/p2_public_surface_observation_identity.h"

using namespace kivo::playback::p2_public_surface_observation;

void test_p2_public_surface_observation_anchor_default_construction();
void test_p2_public_surface_observation_classification_default_construction();
void test_p2_public_surface_observation_observation_default_construction();
void test_p2_public_surface_observation_outcome_default_construction();
void test_p2_public_surface_observation_boundary_cross_family();

int main() {
    P2PublicSurfaceObservationIdentity identity{};
    assert(identity.observation_id.value == 0);
    assert(identity.sequence_id.value == 0);
    assert(identity.generation.value == 0);
    test_p2_public_surface_observation_anchor_default_construction();
    test_p2_public_surface_observation_classification_default_construction();
    test_p2_public_surface_observation_observation_default_construction();
    test_p2_public_surface_observation_outcome_default_construction();
    test_p2_public_surface_observation_boundary_cross_family();
    std::cout << "p2_public_surface_observation tests passed" << std::endl;
    return 0;
}
