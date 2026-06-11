#include <cassert>
#include <iostream>

#include "playback/public_error_recovery/recovery/playback_public_error_recovery.h"
#include "playback/public_error_recovery/recovery/public_error_recovery_candidate.h"
#include "playback/public_error_recovery/recovery/public_error_recovery_envelope.h"
#include "playback/public_error_recovery/recovery/public_error_recovery_record.h"

using namespace kivo::playback::public_error_recovery;

void test_public_error_recovery_recovery_default_construction() {
    PublicErrorRecoveryCandidate candidate{};
    assert(candidate.identity.recovery_id.value == 0);
    assert(candidate.anchors.end_anchor.end_identity.end_id.value == 0);
    assert(candidate.classification.kind == PublicErrorRecoveryKind::Unknown);
    PlaybackPublicErrorRecovery recovery{};
    assert(recovery.identity.recovery_id.value == 0);
    PublicErrorRecoveryEnvelope envelope{};
    assert(envelope.identity.recovery_id.value == 0);
    PublicErrorRecoveryRecord record{};
    assert(record.envelope.identity.recovery_id.value == 0);
    assert(record.recovery.identity.recovery_id.value == 0);
    std::cout << "PASS: test_public_error_recovery_recovery_default_construction" << std::endl;
}
