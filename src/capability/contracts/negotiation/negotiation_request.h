#pragma once
#include <vector>
#include "../requirement/capability_requirement.h"
#include "negotiation_preference.h"
namespace kivo::playback::capability {
struct NegotiationRequest { std::vector<CapabilityRequirement> requirements; NegotiationPreference preference{NegotiationPreference::AnyPath}; };
}
