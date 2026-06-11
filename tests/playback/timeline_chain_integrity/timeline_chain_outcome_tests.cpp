#include <cassert>
#include <iostream>
#include "playback/timeline_chain_integrity/outcome/timeline_chain_integrity_status.h"
#include "playback/timeline_chain_integrity/outcome/timeline_chain_integrity_outcome.h"
#include "playback/timeline_chain_integrity/outcome/timeline_chain_rejection_reason.h"
#include "playback/timeline_chain_integrity/outcome/timeline_chain_drop_reason.h"
namespace kivo::playback::timeline_chain_integrity {
void run_timeline_chain_outcome_tests() {
    assert(static_cast<int>(TimelineChainIntegrityStatus::Recorded) != static_cast<int>(TimelineChainIntegrityStatus::Rejected));
    assert(static_cast<int>(TimelineChainRejectionReason::AnchorMissing) != static_cast<int>(TimelineChainRejectionReason::IntegrityPolicyInvalid));
    assert(static_cast<int>(TimelineChainDropReason::Superseded) != static_cast<int>(TimelineChainDropReason::PriorityOverridden));
    TimelineChainIntegrityOutcome o1; assert(o1.status == TimelineChainIntegrityStatus::Unknown);
    TimelineChainIntegrityIdentity ident{.integrity_id{10}, .sequence_id{20}, .generation{30}};
    TimelineChainIntegrityOutcome o2{ident, TimelineChainIntegrityStatus::Recorded};
    assert(o2.identity.integrity_id.value == 10); assert(o2.status == TimelineChainIntegrityStatus::Recorded);
    std::cout << "  timeline_chain_outcome_tests: ALL PASSED\n";
}
}
