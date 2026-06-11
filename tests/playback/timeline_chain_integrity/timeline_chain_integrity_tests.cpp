#include <cassert>
#include <iostream>
#include "playback/timeline_chain_integrity/integrity/timeline_chain_anchor_set.h"
#include "playback/timeline_chain_integrity/integrity/timeline_chain_integrity_relation.h"
#include "playback/timeline_chain_integrity/integrity/timeline_chain_integrity_status_hint.h"
#include "playback/timeline_chain_integrity/integrity/timeline_chain_integrity_candidate.h"
#include "playback/timeline_chain_integrity/integrity/playback_timeline_chain_integrity.h"
#include "playback/timeline_chain_integrity/integrity/timeline_chain_integrity_envelope.h"
#include "playback/timeline_chain_integrity/integrity/timeline_chain_integrity_record.h"
namespace kivo::playback::timeline_chain_integrity {
void run_timeline_chain_integrity_tests() {
    assert(static_cast<int>(TimelineChainIntegrityRelation::RequestToDecision) != static_cast<int>(TimelineChainIntegrityRelation::SnapshotToSummary));
    assert(static_cast<int>(TimelineChainIntegrityStatusHint::Complete) != static_cast<int>(TimelineChainIntegrityStatusHint::MissingAnchor));
    TimelineChainIntegrityIdentity ident{.integrity_id{1}, .sequence_id{2}, .generation{3}};
    TimelineChainAnchorSet anchors; assert(anchors.request_anchor.request_identity.request_id.value == 0);
    TimelineChainIntegrityCandidate c1; assert(c1.identity.integrity_id.value == 0);
    TimelineChainIntegrityCandidate c2{ident, anchors}; assert(c2.identity.integrity_id.value == 1);
    PlaybackTimelineChainIntegrity i1; assert(i1.identity.integrity_id.value == 0);
    PlaybackTimelineChainIntegrity i2{ident, anchors}; assert(i2.identity.integrity_id.value == 1);
    TimelineChainIntegrityEnvelope env1; assert(env1.identity.integrity_id.value == 0);
    TimelineChainIntegrityEnvelope env2{ident, anchors}; assert(env2.identity.integrity_id.value == 1);
    TimelineChainIntegrityRecord rec1; assert(rec1.envelope.identity.integrity_id.value == 0);
    TimelineChainIntegrityRecord rec2{env2, i2}; assert(rec2.envelope.identity.integrity_id.value == 1);
    assert(rec2.integrity.identity.integrity_id.value == 1);
    std::cout << "  timeline_chain_integrity_tests: ALL PASSED\n";
}
}
