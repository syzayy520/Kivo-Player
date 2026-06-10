#include <cassert>
#include <iostream>
#include "playback/control/normalization/control_normalization_policy.h"
#include "playback/control/normalization/control_normalization_decision.h"
#include "playback/control/normalization/normalized_playback_intent.h"
#include "playback/control/normalization/control_normalization_record.h"
namespace kivo::playback::control {
void run_control_normalization_tests() {
    ControlNormalizationPolicy pol1 = ControlNormalizationPolicy::Strict; ControlNormalizationPolicy pol2 = ControlNormalizationPolicy::Lenient; ControlNormalizationPolicy pol3 = ControlNormalizationPolicy::PreserveUnknown;
    assert(pol1 != pol2); assert(pol2 != pol3);
    ControlNormalizationDecision d1 = ControlNormalizationDecision::Accepted; ControlNormalizationDecision d2 = ControlNormalizationDecision::Rejected; ControlNormalizationDecision d3 = ControlNormalizationDecision::Dropped;
    assert(d1 != d2); assert(d2 != d3);
    NormalizedPlaybackIntent ni1;
    assert(ni1.request_id.value == 0); assert(ni1.intent.intent_id.value == 0);
    NormalizedPlaybackIntent ni2{.request_id{ControlRequestId{1}}, .intent{kivo::playback::orchestration::PlaybackIntent{.intent_id{kivo::playback::orchestration::PlaybackIntentId{2}}, .kind{kivo::playback::orchestration::PlaybackIntentKind::Play}, .session_id{kivo::playback::orchestration::PlaybackSessionId{3}}}}};
    assert(ni2.intent.kind == kivo::playback::orchestration::PlaybackIntentKind::Play);
    ControlNormalizationRecord rec1;
    assert(rec1.decision == ControlNormalizationDecision::Unknown);
    assert(rec1.target.kind == PlaybackControlTargetKind::Unknown);
    ControlNormalizationRecord rec2{
        .identity{.command_id{1}, .sequence_id{2}, .request_id{3}},
        .source{.source_id{4}, .kind{ControlSourceKind::User}, .origin{ControlOriginKind::Local}},
        .command{.identity{.command_id{1}}, .kind{PlaybackControlCommandKind::Play}},
        .target{.kind{PlaybackControlTargetKind::Session}},
        .policy{ControlNormalizationPolicy::Strict},
        .normalized_intent{ni2},
        .decision{ControlNormalizationDecision::Accepted}
    };
    assert(rec2.identity.request_id.value == 3);
    assert(rec2.source.kind == ControlSourceKind::User);
    assert(rec2.target.kind == PlaybackControlTargetKind::Session);
    assert(rec2.decision == ControlNormalizationDecision::Accepted);
    std::cout << "  control_normalization_tests: ALL PASSED\n";
}
}
