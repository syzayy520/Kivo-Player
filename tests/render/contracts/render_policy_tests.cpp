#include <cassert>
#include <iostream>
#include "render/contracts/policy/render_pacing_policy.h"
#include "render/contracts/policy/render_color_policy.h"
#include "render/contracts/policy/render_hdr_policy.h"
#include "render/contracts/policy/render_failure_policy.h"

namespace kivo::playback::render {
void run_render_policy_tests() {
    // Test RenderPacingPolicy (approved: FollowPresentationPacing, FreeRun)
    RenderPacingPolicy pacing1 = RenderPacingPolicy::FollowPresentationPacing;
    RenderPacingPolicy pacing2 = RenderPacingPolicy::FreeRun;
    assert(pacing1 != pacing2);
    
    // Test RenderColorPolicy (approved: RenderColorIntent intent only)
    RenderColorPolicy color1;
    assert(color1.intent == RenderColorIntent::Unknown);
    
    RenderColorPolicy color2{.intent{RenderColorIntent::PassthroughColor}};
    assert(color2.intent == RenderColorIntent::PassthroughColor);
    
    // Test RenderColorIntent
    RenderColorIntent intent1 = RenderColorIntent::PassthroughColor;
    RenderColorIntent intent2 = RenderColorIntent::MatchTargetColor;
    assert(intent1 != intent2);
    
    // Test RenderHdrPolicy (approved: RenderHdrIntent + HdrStaticMetadata)
    RenderHdrPolicy hdr1;
    assert(hdr1.intent == RenderHdrIntent::Unknown);
    assert(hdr1.hdr_metadata.mastering.max_luminance == 0.0f);
    
    RenderHdrPolicy hdr2{
        .intent{RenderHdrIntent::ToneMapToReference},
        .hdr_metadata{.mastering{.max_luminance{1000.0f}}}
    };
    assert(hdr2.intent == RenderHdrIntent::ToneMapToReference);
    assert(hdr2.hdr_metadata.mastering.max_luminance == 1000.0f);
    
    // Test RenderHdrIntent
    RenderHdrIntent hintent1 = RenderHdrIntent::PassthroughHdr;
    RenderHdrIntent hintent2 = RenderHdrIntent::ToneMapToReference;
    RenderHdrIntent hintent3 = RenderHdrIntent::ToneMapToTarget;
    assert(hintent1 != hintent2);
    assert(hintent2 != hintent3);
    
    // Test RenderFailurePolicy (approved: AbortSubmission,SkipFrame,RetryOnce,NotifyAndContinue,Unknown)
    RenderFailurePolicy failure1 = RenderFailurePolicy::AbortSubmission;
    RenderFailurePolicy failure2 = RenderFailurePolicy::SkipFrame;
    RenderFailurePolicy failure3 = RenderFailurePolicy::RetryOnce;
    RenderFailurePolicy failure4 = RenderFailurePolicy::NotifyAndContinue;
    RenderFailurePolicy failure5 = RenderFailurePolicy::Unknown;
    assert(failure1 != failure2);
    assert(failure2 != failure3);
    assert(failure3 != failure4);
    assert(failure4 != failure5);
    
    std::cout << "  render_policy_tests: ALL PASSED\n";
}
}

// main() is in render_identity_tests.cpp
