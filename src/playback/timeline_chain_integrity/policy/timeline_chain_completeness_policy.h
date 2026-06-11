#pragma once
namespace kivo::playback::timeline_chain_integrity {
enum class TimelineChainCompletenessPolicy { AllowPartialChain, RequireDecisionAndResult, RequireSnapshotAndSummary, Unknown };
}
