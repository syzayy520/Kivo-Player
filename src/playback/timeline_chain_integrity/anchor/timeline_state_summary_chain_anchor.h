#pragma once
#include "playback/timeline_state_summary/identity/timeline_state_summary_identity.h"
namespace kivo::playback::timeline_chain_integrity {
struct TimelineStateSummaryChainAnchor { kivo::playback::timeline_state_summary::TimelineStateSummaryIdentity state_summary_identity{}; };
}
