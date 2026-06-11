#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_coherence_view/anchor/p2_public_surface_integrity_coherence_view_anchor.h"
#include "playback/p2_public_surface_coherence_view/anchor/p2_public_surface_coherence_view_anchor_set.h"

using namespace kivo::playback::p2_public_surface_coherence_view;
using namespace kivo::playback::p2_public_surface_integrity_audit;

void test_p2_public_surface_coherence_view_anchor_default_construction() {
    P2PublicSurfaceIntegrityCoherenceViewAnchor anchor{};
    assert(anchor.integrity_identity.audit_id.value == 0);
    anchor.integrity_identity.audit_id = P2PublicSurfaceIntegrityAuditId{123};
    assert(anchor.integrity_identity.audit_id.value == 123);
    P2PublicSurfaceCoherenceViewAnchorSet anchor_set{};
    assert(anchor_set.integrity_anchor.integrity_identity.audit_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_coherence_view_anchor_default_construction" << std::endl;
}
