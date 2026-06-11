#pragma once
namespace kivo::playback::timeline_chain_integrity {
enum class TimelineChainIntegrityRelation { RequestToDecision, DecisionToResult, ResultToSnapshot, SnapshotToSummary, Unknown };
}
