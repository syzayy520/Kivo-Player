// Copyright (c) 2026 Kivo Project. All rights reserved.
#include "capability/contracts/identity/capability_subject.h"
#include "capability/contracts/scope/capability_scope.h"
#include "capability/contracts/scope/capability_path.h"
#include "capability/contracts/scope/capability_level.h"
#include "capability/contracts/scope/capability_status.h"
#include "capability/contracts/scope/capability_source.h"
#include "capability/contracts/scope/capability_confidence.h"
#include "capability/contracts/scope/capability_truth_source.h"
#include <cassert>

int run_capability_media_tests();
int run_capability_memory_tests();
int run_capability_requirement_tests();
int run_capability_negotiation_tests();

int main() {
    using namespace kivo::playback::capability;
    assert(static_cast<int>(CapabilitySubject::Engine) == 0);
    assert(static_cast<int>(CapabilityScope::Video) == 0);
    assert(static_cast<int>(CapabilityPath::Unknown) == 4);
    assert(CapabilityLevel::Full != CapabilityLevel::Unsupported);
    assert(CapabilityStatus::Verified != CapabilityStatus::Disabled);
    assert(CapabilitySource::AdapterReported != CapabilitySource::FallbackDefault);
    assert(CapabilityConfidence::Certain != CapabilityConfidence::Unknown);
    assert(CapabilityTruthSource::SelfReported != CapabilityTruthSource::Inferred);
    assert(run_capability_media_tests() == 0);
    assert(run_capability_memory_tests() == 0);
    assert(run_capability_requirement_tests() == 0);
    assert(run_capability_negotiation_tests() == 0);
    return 0;
}
