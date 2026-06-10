#pragma once
#include "../scope/capability_scope.h"
#include "../scope/capability_level.h"
#include "../scope/capability_status.h"
#include "../scope/capability_source.h"
#include "../scope/capability_confidence.h"
#include "../scope/capability_truth_source.h"
namespace kivo::playback::capability {
struct CapabilityResult { CapabilityScope scope{CapabilityScope::Video}; CapabilityLevel level{CapabilityLevel::Unknown}; CapabilityStatus status{CapabilityStatus::Assumed}; CapabilitySource source{CapabilitySource::FallbackDefault}; CapabilityConfidence confidence{CapabilityConfidence::Unknown}; CapabilityTruthSource truth_source{CapabilityTruthSource::Inferred}; };
}
