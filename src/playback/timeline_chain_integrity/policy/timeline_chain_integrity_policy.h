#pragma once
#include "timeline_chain_integrity_kind.h"
#include "timeline_chain_completeness_policy.h"
#include "timeline_chain_priority.h"
namespace kivo::playback::timeline_chain_integrity {
struct TimelineChainIntegrityPolicy { TimelineChainIntegrityKind integrity_kind{TimelineChainIntegrityKind::Unknown}; TimelineChainCompletenessPolicy completeness_policy{TimelineChainCompletenessPolicy::Unknown}; TimelineChainPriority priority{TimelineChainPriority::Unknown}; };
}
