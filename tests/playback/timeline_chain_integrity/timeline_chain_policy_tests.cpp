#include <cassert>
#include <iostream>
#include "playback/timeline_chain_integrity/policy/timeline_chain_integrity_kind.h"
#include "playback/timeline_chain_integrity/policy/timeline_chain_completeness_policy.h"
#include "playback/timeline_chain_integrity/policy/timeline_chain_priority.h"
#include "playback/timeline_chain_integrity/policy/timeline_chain_integrity_policy.h"
namespace kivo::playback::timeline_chain_integrity {
void run_timeline_chain_policy_tests() {
    assert(static_cast<int>(TimelineChainIntegrityKind::IdentityPresenceOnly) != static_cast<int>(TimelineChainIntegrityKind::LinkedIdentitySet));
    assert(static_cast<int>(TimelineChainCompletenessPolicy::AllowPartialChain) != static_cast<int>(TimelineChainCompletenessPolicy::RequireSnapshotAndSummary));
    assert(static_cast<int>(TimelineChainPriority::Low) != static_cast<int>(TimelineChainPriority::High));
    TimelineChainIntegrityPolicy p1; assert(p1.integrity_kind == TimelineChainIntegrityKind::Unknown);
    TimelineChainIntegrityPolicy p2{TimelineChainIntegrityKind::LinkedIdentitySet, TimelineChainCompletenessPolicy::RequireDecisionAndResult, TimelineChainPriority::High};
    assert(p2.integrity_kind == TimelineChainIntegrityKind::LinkedIdentitySet);
    assert(p2.completeness_policy == TimelineChainCompletenessPolicy::RequireDecisionAndResult);
    assert(p2.priority == TimelineChainPriority::High);
    std::cout << "  timeline_chain_policy_tests: ALL PASSED\n";
}
}
