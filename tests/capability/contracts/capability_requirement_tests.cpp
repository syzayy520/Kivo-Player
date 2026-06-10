// Copyright (c) 2026 Kivo Project. All rights reserved.
#include "capability/contracts/requirement/requirement_strictness.h"
#include "capability/contracts/requirement/capability_requirement.h"
#include "capability/contracts/requirement/capability_result.h"
#include <cassert>

int run_capability_requirement_tests() {
    using namespace kivo::playback::capability;
    assert(RequirementStrictness::Required != RequirementStrictness::Optional);
    CapabilityRequirement cr{CapabilityScope::Video, CapabilityLevel::Full, RequirementStrictness::Required};
    assert(cr.scope == CapabilityScope::Video);
    assert(cr.strictness == RequirementStrictness::Required);
    CapabilityResult crs{CapabilityScope::Video, CapabilityLevel::Full, CapabilityStatus::Verified, CapabilitySource::AdapterReported, CapabilityConfidence::Certain, CapabilityTruthSource::SelfReported};
    assert(crs.level == CapabilityLevel::Full);
    assert(crs.status == CapabilityStatus::Verified);
    assert(crs.confidence == CapabilityConfidence::Certain);
    return 0;
}
