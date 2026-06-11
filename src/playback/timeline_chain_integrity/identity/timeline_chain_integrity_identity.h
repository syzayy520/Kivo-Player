#pragma once
#include "timeline_chain_integrity_id.h"
#include "timeline_chain_integrity_sequence_id.h"
#include "timeline_chain_integrity_generation.h"
namespace kivo::playback::timeline_chain_integrity {
struct TimelineChainIntegrityIdentity { TimelineChainIntegrityId integrity_id{}; TimelineChainIntegritySequenceId sequence_id{}; TimelineChainIntegrityGeneration generation{}; };
}
