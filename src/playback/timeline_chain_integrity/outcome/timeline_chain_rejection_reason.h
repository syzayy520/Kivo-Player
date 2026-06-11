#pragma once
namespace kivo::playback::timeline_chain_integrity {
enum class TimelineChainRejectionReason { AnchorMissing, ChainIdentityMissing, IntegrityPolicyInvalid, Unknown };
}
