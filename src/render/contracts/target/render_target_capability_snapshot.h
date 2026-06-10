#pragma once
#include "render_target_id.h"
#include "capability/contracts/requirement/capability_result.h"
#include "capability/contracts/negotiation/negotiation_result.h"
namespace kivo::playback::render {
struct RenderTargetCapabilitySnapshot {
    RenderTargetId target_id{};
    kivo::playback::capability::CapabilityResult capability_result{};
    kivo::playback::capability::NegotiationResult negotiation_result{};
};
}
