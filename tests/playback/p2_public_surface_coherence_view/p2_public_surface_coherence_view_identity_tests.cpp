#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_coherence_view/identity/p2_public_surface_coherence_view_identity.h"

using namespace kivo::playback::p2_public_surface_coherence_view;

void test_p2_public_surface_coherence_view_anchor_default_construction();
void test_p2_public_surface_coherence_view_classification_default_construction();
void test_p2_public_surface_coherence_view_coherence_view_default_construction();
void test_p2_public_surface_coherence_view_outcome_default_construction();
void test_p2_public_surface_coherence_view_boundary_cross_family();

int main() {
    P2PublicSurfaceCoherenceViewIdentity identity{};
    assert(identity.view_id.value == 0);
    assert(identity.sequence_id.value == 0);
    assert(identity.generation.value == 0);
    test_p2_public_surface_coherence_view_anchor_default_construction();
    test_p2_public_surface_coherence_view_classification_default_construction();
    test_p2_public_surface_coherence_view_coherence_view_default_construction();
    test_p2_public_surface_coherence_view_outcome_default_construction();
    test_p2_public_surface_coherence_view_boundary_cross_family();
    std::cout << "p2_public_surface_coherence_view tests passed" << std::endl;
    return 0;
}
