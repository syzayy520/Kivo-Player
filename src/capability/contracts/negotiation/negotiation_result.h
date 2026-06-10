#pragma once
#include "../scope/capability_level.h"
#include "negotiation_match.h"
#include "negotiation_candidate.h"
#include "negotiation_failure_reason.h"
namespace kivo::playback::capability {
enum class NegotiationCandidatePresence { CandidateFound, NoCandidate };
struct NegotiationResult { NegotiationMatch match{NegotiationMatch::Rejected}; NegotiationCandidatePresence candidate_present{NegotiationCandidatePresence::NoCandidate}; NegotiationCandidate candidate{}; NegotiationFailureReason failure{NegotiationFailureReason::ScopeUnavailable}; CapabilityLevel overall_level{CapabilityLevel::Unknown}; };
}
