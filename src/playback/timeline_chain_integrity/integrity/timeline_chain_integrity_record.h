#pragma once
#include "timeline_chain_integrity_envelope.h"
#include "playback_timeline_chain_integrity.h"
namespace kivo::playback::timeline_chain_integrity {
struct TimelineChainIntegrityRecord { TimelineChainIntegrityEnvelope envelope{}; PlaybackTimelineChainIntegrity integrity{}; };
}
