#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_snapshot/identity/p2_public_surface_snapshot_identity.h"

using namespace kivo::playback::p2_public_surface_snapshot;

void test_p2_public_surface_snapshot_anchor_default_construction();
void test_p2_public_surface_snapshot_classification_default_construction();
void test_p2_public_surface_snapshot_snapshot_default_construction();
void test_p2_public_surface_snapshot_outcome_default_construction();
void test_p2_public_surface_snapshot_boundary_cross_family();

int main() {
    P2PublicSurfaceSnapshotIdentity identity{};
    assert(identity.snapshot_id.value == 0);
    assert(identity.sequence_id.value == 0);
    assert(identity.generation.value == 0);
    test_p2_public_surface_snapshot_anchor_default_construction();
    test_p2_public_surface_snapshot_classification_default_construction();
    test_p2_public_surface_snapshot_snapshot_default_construction();
    test_p2_public_surface_snapshot_outcome_default_construction();
    test_p2_public_surface_snapshot_boundary_cross_family();
    std::cout << "p2_public_surface_snapshot tests passed" << std::endl;
    return 0;
}
