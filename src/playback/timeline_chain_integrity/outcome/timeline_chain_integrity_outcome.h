#pragma once
#include "../identity/timeline_chain_integrity_identity.h"
#include "timeline_chain_integrity_status.h"
namespace kivo::playback::timeline_chain_integrity {
struct TimelineChainIntegrityOutcome { TimelineChainIntegrityIdentity identity{}; TimelineChainIntegrityStatus status{TimelineChainIntegrityStatus::Unknown}; };
}
