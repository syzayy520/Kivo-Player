#pragma once
#include "../identity/timeline_chain_integrity_identity.h"
#include "timeline_chain_anchor_set.h"
#include "../policy/timeline_chain_integrity_policy.h"
namespace kivo::playback::timeline_chain_integrity {
struct TimelineChainIntegrityEnvelope { TimelineChainIntegrityIdentity identity{}; TimelineChainAnchorSet anchors{}; TimelineChainIntegrityPolicy policy{}; };
}
