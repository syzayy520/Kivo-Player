// Copyright (c) 2026 Kivo Project. All rights reserved.
#include "capability/contracts/negotiation/negotiation_preference.h"
#include "capability/contracts/negotiation/negotiation_match.h"
#include "capability/contracts/negotiation/negotiation_candidate.h"
#include "capability/contracts/negotiation/negotiation_failure_reason.h"
#include "capability/contracts/negotiation/negotiation_result.h"
#include "capability/contracts/negotiation/negotiation_request.h"
#include <cassert>

int run_capability_negotiation_tests() {
    using namespace kivo::playback::capability;
    assert(NegotiationPreference::PreferDedicatedPath != NegotiationPreference::AnyPath);
    NegotiationMatch m = NegotiationMatch::ExactMatch;
    assert(m == NegotiationMatch::ExactMatch);
    NegotiationCandidate nc{1, CapabilityLevel::Full, true};
    assert(nc.profile_id == 1);
    assert(nc.satisfies_all_required);
    assert(NegotiationFailureReason::NoCapablePath != NegotiationFailureReason::UserRejected);
    NegotiationResult nr{NegotiationMatch::ExactMatch, NegotiationCandidatePresence::CandidateFound, nc, NegotiationFailureReason::NoCapablePath, CapabilityLevel::Full};
    assert(nr.match == NegotiationMatch::ExactMatch);
    assert(nr.candidate_present == NegotiationCandidatePresence::CandidateFound);
    assert(nr.candidate.profile_id == 1);
    NegotiationRequest nreq;
    nreq.preference = NegotiationPreference::PreferDedicatedPath;
    assert(nreq.preference == NegotiationPreference::PreferDedicatedPath);
    return 0;
}
