#pragma once
#include "../scope/capability_scope.h"
#include "../scope/capability_level.h"
#include "requirement_strictness.h"
namespace kivo::playback::capability {
struct CapabilityRequirement { CapabilityScope scope{CapabilityScope::Video}; CapabilityLevel minimum_level{CapabilityLevel::Unknown}; RequirementStrictness strictness{RequirementStrictness::Optional}; };
}
