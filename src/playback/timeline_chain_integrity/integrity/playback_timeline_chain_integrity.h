#pragma once
#include "../identity/timeline_chain_integrity_identity.h"
#include "timeline_chain_anchor_set.h"
namespace kivo::playback::timeline_chain_integrity {
struct PlaybackTimelineChainIntegrity { TimelineChainIntegrityIdentity identity{}; TimelineChainAnchorSet anchors{}; };
}
