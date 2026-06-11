#include <cassert>
#include <iostream>

#include "playback/p1_public_surface_closure_audit/identity/p1_public_surface_closure_audit_identity.h"

using namespace kivo::playback::p1_public_surface_closure_audit;

void test_p1_public_surface_closure_audit_anchor_default_construction();
void test_p1_public_surface_closure_audit_classification_default_construction();
void test_p1_public_surface_closure_audit_audit_default_construction();
void test_p1_public_surface_closure_audit_outcome_default_construction();
void test_p1_public_surface_closure_audit_boundary_cross_family();

int main() {
    P1PublicSurfaceClosureAuditIdentity identity{};
    assert(identity.audit_id.value == 0);
    assert(identity.sequence_id.value == 0);
    assert(identity.generation.value == 0);
    test_p1_public_surface_closure_audit_anchor_default_construction();
    test_p1_public_surface_closure_audit_classification_default_construction();
    test_p1_public_surface_closure_audit_audit_default_construction();
    test_p1_public_surface_closure_audit_outcome_default_construction();
    test_p1_public_surface_closure_audit_boundary_cross_family();
    std::cout << "p1_public_surface_closure_audit tests passed" << std::endl;
    return 0;
}
