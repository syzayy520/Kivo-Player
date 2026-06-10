#pragma once
#include <cstdint>
#include "../scope/capability_level.h"
namespace kivo::playback::capability {
struct NegotiationCandidate { uint32_t profile_id{0}; CapabilityLevel overall{CapabilityLevel::Unknown}; bool satisfies_all_required{false}; };
}
