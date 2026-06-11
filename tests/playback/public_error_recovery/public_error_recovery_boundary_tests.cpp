#include <cassert>
#include <iostream>

#include "playback/public_error_recovery/identity/public_error_recovery_identity.h"
#include "playback/public_error_recovery/anchor/end_of_stream_public_recovery_anchor.h"
#include "playback/public_error_recovery/recovery/playback_public_error_recovery.h"
#include "playback/public_error_recovery/outcome/public_error_recovery_outcome.h"

using namespace kivo::playback::public_error_recovery;

void test_public_error_recovery_boundary_cross_family() {
    EndOfStreamPublicRecoveryAnchor anchor{};
    anchor.end_identity.end_id = kivo::playback::end_of_stream_public::EndOfStreamPublicId{123};
    assert(anchor.end_identity.end_id.value == 123);
    PlaybackPublicErrorRecovery recovery{
        .identity = PublicErrorRecoveryIdentity{.recovery_id = PublicErrorRecoveryId{1}},
        .anchors = PublicErrorRecoveryAnchorSet{.end_anchor = anchor},
        .classification = PublicErrorRecoveryClassification{.kind = PublicErrorRecoveryKind::Recoverable, .scope = PublicErrorRecoveryScope::Timeline}
    };
    assert(recovery.identity.recovery_id.value == 1);
    assert(recovery.anchors.end_anchor.end_identity.end_id.value == 123);
    assert(recovery.classification.kind == PublicErrorRecoveryKind::Recoverable);
    assert(recovery.classification.scope == PublicErrorRecoveryScope::Timeline);
    PublicErrorRecoveryOutcome outcome{.identity = PublicErrorRecoveryIdentity{.recovery_id = PublicErrorRecoveryId{42}}, .status = PublicErrorRecoveryStatus::Recorded};
    assert(outcome.identity.recovery_id.value == 42);
    assert(outcome.status == PublicErrorRecoveryStatus::Recorded);
    std::cout << "PASS: test_public_error_recovery_boundary_cross_family" << std::endl;
}
