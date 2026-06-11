#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_activation_audit/identity/p2_public_surface_activation_audit_identity.h"
#include "playback/p2_public_surface_activation_audit/anchor/p2_public_surface_activation_view_audit_anchor.h"
#include "playback/p2_public_surface_activation_audit/audit/playback_p2_public_surface_activation_audit.h"
#include "playback/p2_public_surface_activation_audit/outcome/p2_public_surface_activation_audit_outcome.h"

using namespace kivo::playback::p2_public_surface_activation_audit;

void test_p2_public_surface_activation_audit_boundary_cross_family() {
    P2PublicSurfaceActivationViewAuditAnchor anchor{};
    anchor.activation_view_identity.view_id = kivo::playback::p2_public_surface_activation_view::P2PublicSurfaceActivationViewId{123};
    assert(anchor.activation_view_identity.view_id.value == 123);
    PlaybackP2PublicSurfaceActivationAudit audit{
        .identity = P2PublicSurfaceActivationAuditIdentity{.audit_id = P2PublicSurfaceActivationAuditId{1}},
        .anchors = P2PublicSurfaceActivationAuditAnchorSet{.activation_view_anchor = anchor},
        .classification = P2PublicSurfaceActivationAuditClassification{.kind = P2PublicSurfaceActivationAuditKind::SurfaceActive, .scope = P2PublicSurfaceActivationAuditScope::AuditBoundary}
    };
    assert(audit.identity.audit_id.value == 1);
    assert(audit.anchors.activation_view_anchor.activation_view_identity.view_id.value == 123);
    assert(audit.classification.kind == P2PublicSurfaceActivationAuditKind::SurfaceActive);
    assert(audit.classification.scope == P2PublicSurfaceActivationAuditScope::AuditBoundary);
    P2PublicSurfaceActivationAuditOutcome outcome{.identity = P2PublicSurfaceActivationAuditIdentity{.audit_id = P2PublicSurfaceActivationAuditId{42}}, .status = P2PublicSurfaceActivationAuditStatus::Recorded};
    assert(outcome.identity.audit_id.value == 42);
    assert(outcome.status == P2PublicSurfaceActivationAuditStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_activation_audit_boundary_cross_family" << std::endl;
}
